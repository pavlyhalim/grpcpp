#ifndef CLIENT_H
#define CLIENT_H

#include <fstream>
#include <iostream>
#include <grpcpp/grpcpp.h>
#include "file_exchange.grpc.pb.h"

class FileExchangeClient {
public:
    explicit FileExchangeClient(const std::shared_ptr<grpc::Channel>& channel,
                                std::unique_ptr<example::FileExchange::StubInterface> stub = nullptr)
        : stub_(std::move(stub ? std::move(stub) : example::FileExchange::NewStub(channel))) {}

    bool SendData(const std::string& numberStr);
    bool SendString(const std::string& text);
    bool SendFile(const std::string& file_path);

    example::FileExchange::StubInterface* getTestingStub() const {
        return stub_.get();
    }

private:
    std::shared_ptr<grpc::Channel> channel_;
    std::unique_ptr<example::FileExchange::StubInterface> stub_;
};


#endif
