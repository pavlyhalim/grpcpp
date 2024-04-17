#include <fstream>
#include <iostream>
#include <grpcpp/grpcpp.h>
#include "file_exchange.grpc.pb.h"

using namespace grpc;
using namespace example;

class FileExchangeImpl final : public FileExchange::Service {
    Status SendData(ServerContext* context, const DataRequest* request, DataResponse* response) override {
        response->set_confirmation("Number received: " + std::to_string(request->number()));
        std::cout << "Received number: " << request->number() << std::endl;
        return Status::OK;
    }

    Status SendString(ServerContext* context, const StringRequest* request, StringResponse* response) override {
        response->set_confirmation("String received: " + request->text());
        std::cout << "Received string: " << request->text() << std::endl;
        return Status::OK;
    }

    Status SendFile(ServerContext* context, ServerReader<FileChunk>* reader, FileResponse* response) override {
        std::string filename;
        std::ofstream out;
        FileChunk chunk;
        bool firstChunk = true;

        while (reader->Read(&chunk)) {
            if (firstChunk) {
                if (chunk.filename().empty()) {
                    std::cerr << "Filename is missing in the first chunk." << std::endl;
                    return Status(StatusCode::INVALID_ARGUMENT, "Filename is missing in the first chunk.");
                }
                filename = chunk.filename();
                out.open(filename, std::ios::binary);
                if (!out.is_open()) {
                    std::cerr << "Failed to open file: " << filename << std::endl;
                    return Status(StatusCode::INTERNAL, "Failed to open file for writing.");
                }
                firstChunk = false; 
            }

            out.write(chunk.content().data(), chunk.content().size());
        }
        out.close();

        if (!out.good()) { 
            std::cerr << "Failed to write all data to file: " << filename << std::endl;
            return Status(StatusCode::INTERNAL, "Failed to write all data to file.");
        }

        std::cout << "Received file: " << filename << std::endl;
        response->set_confirmation("File received successfully: " + filename);
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    FileExchangeImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}
