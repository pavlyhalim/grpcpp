#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <grpcpp/grpcpp.h>
#include "file_exchange.grpc.pb.h"

using namespace std;
using namespace grpc;
using namespace example;

class FileExchangeClient {
public:
    explicit FileExchangeClient(const shared_ptr<Channel>& channel)
        : stub_(FileExchange::NewStub(channel)) {}

    bool SendData(int64_t number) {
        if (number < INT64_MIN || number > INT64_MAX) {
            cerr << "Number is out of range." << endl;
            return false;
        }
        DataRequest request;
        request.set_number(number);
        DataResponse response;
        ClientContext context;

        Status status = stub_->SendData(&context, request, &response);
        if (!status.ok()) {
            cerr << "RPC failed: " << status.error_message() << endl;
            return false;
        }
        cout << "Server response: " << response.confirmation() << endl;
        return true;
    }

    bool SendString(const string& text) {
        if (text.length() > 1024) {
            cerr << "String exceeds maximum length of 1024 characters." << endl;
            return false;
        }
        StringRequest request;
        request.set_text(text);
        StringResponse response;
        ClientContext context;

        Status status = stub_->SendString(&context, request, &response);
        if (!status.ok()) {
            cerr << "RPC failed: " << status.error_message() << endl;
            return false;
        }
        cout << "Server response: " << response.confirmation() << endl;
        return true;
    }

    bool SendFile(const string& file_path) {
        ifstream file(file_path, ios::binary);
        if (!file) {
            cerr << "Failed to open file: " << file_path << endl;
            return false;
        }

        FileResponse response;
        ClientContext context;
        unique_ptr<ClientWriter<FileChunk>> writer(stub_->SendFile(&context, &response));
        FileChunk chunk;
        char buffer[1024 * 1024];
        bool firstChunk = true;

        while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
            if (firstChunk) {
                chunk.set_filename(file_path.substr(file_path.find_last_of("/\\") + 1));
                firstChunk = false;
            }
            chunk.set_content(buffer, file.gcount());
            if (!writer->Write(chunk)) {
                cerr << "Broken stream when sending file." << endl;
                return false;
            }
            chunk.clear_filename(); 
        }
        writer->WritesDone();
        Status status = writer->Finish();
        if (!status.ok()) {
            cerr << "Failed to send file: " << status.error_message() << endl;
            return false;
        }
        cout << "File sent successfully. Server response: " << response.confirmation() << endl;
        return true;
    }

private:
    unique_ptr<FileExchange::Stub> stub_;
};

int main() {
    FileExchangeClient client(CreateChannel("localhost:50051", InsecureChannelCredentials()));
    string continueSending;

    do {
        cout << "Enter a number to send to the server: ";
        int64_t number;
        if (!(cin >> number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter a valid integer." << endl;
            continue;
        }

        client.SendData(number);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter a string to send to the server: ";
        string text;
        getline(cin, text);
        client.SendString(text);

        cout << "Enter the path of the file to send to the server: ";
        string file_path;
        getline(cin, file_path);
        client.SendFile(file_path);

        do {
            cout << "Do you want to continue? (y/n): ";
            getline(cin, continueSending);
        } while (!continueSending.empty() && continueSending != "y" && continueSending != "n" && continueSending != "Y" && continueSending != "N");

    } while (!continueSending.empty() && (continueSending == "y" || continueSending == "Y"));

    return 0;
}
