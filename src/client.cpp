#include <iostream>
#include <fstream>
#include "client.h"
#include "catch_amalgamated.hpp"

bool FileExchangeClient::SendData(const std::string& numberStr) {
    int64_t number;
    std::istringstream iss(numberStr);
    if (!(iss >> number) || !iss.eof()) {
        std::cerr << "Input is not a valid 64-bit integer." << std::endl;
        return false;
    }

    example::DataRequest request;
    request.set_number(number);
    example::DataResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->SendData(&context, request, &response);
    if (!status.ok()) {
        std::cerr << "RPC failed: " << status.error_message() << std::endl;
        return false;
    }
    std::cout << "Server response: " << response.confirmation() << std::endl;
    return true;
}

bool FileExchangeClient::SendString(const std::string& text) {
    if (text.length() > 1024) {
        std::cerr << "String exceeds max length of 1024 chars." << std::endl;
        return false;
    }
    example::StringRequest request;
    request.set_text(text);
    example::StringResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->SendString(&context, request, &response);
    if (!status.ok()) {
        std::cerr << "RPC failed: " << status.error_message() << std::endl;
        return false;
    }
    std::cout << "Server response: " << response.confirmation() << std::endl;
    return true;
}

bool FileExchangeClient::SendFile(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return false;
    }

    example::FileResponse response;
    grpc::ClientContext context;
    auto writer = stub_->SendFile(&context, &response);
    if (!writer) {
        std::cerr << "Failed to create file writer." << std::endl;
        return false;
    }

    example::FileChunk chunk;
    char buffer[1024 * 1024];
    bool firstChunk = true;

    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        if (firstChunk) {
            chunk.set_filename(file_path.substr(file_path.find_last_of("/\\") + 1));
            firstChunk = false;
        }
        chunk.set_content(buffer, file.gcount());
        if (!writer->Write(chunk)) {
            std::cerr << "Broken stream when sending file." << std::endl;
            return false;
        }
        chunk.clear_filename(); 
    }
    writer->WritesDone();
    grpc::Status status = writer->Finish();
    if (!status.ok()) {
        std::cerr << "Failed to send file: " << status.error_message() << std::endl;
        return false;
    }
    std::cout << "File sent successfully. Server response: " << response.confirmation() << std::endl;
    return true;
}
