#include "client.h"
#include "catch_amalgamated.hpp"
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    FileExchangeClient client(channel);
    std::string continueSending;

    do {
        std::cout << "Enter a number:";
        std::string numberStr;
        std::getline(std::cin, numberStr);

        if (!client.SendData(numberStr)) {
            std::cerr << "Failed, Please check the format and try again." << std::endl;
        }

        std::cout << "Enter a string:";
        std::string text;
        std::getline(std::cin, text);
        if (!client.SendString(text)) {
            std::cerr << "Failed, Please ensure it is within the character limit." << std::endl;
        }

        std::cout << "Enter the path of the file to send to the server: ";
        std::string file_path;
        std::getline(std::cin, file_path);
        if (!client.SendFile(file_path)) {
            std::cerr << "Failed, Please check the file path and try again." << std::endl;
        }

        do {
            std::cout << "Do you want to continue? (y/n): ";
            std::getline(std::cin, continueSending);
        } while (!continueSending.empty() && continueSending != "y" && continueSending != "n" && continueSending != "Y" && continueSending != "N");

    } while (!continueSending.empty() && (continueSending == "y" || continueSending == "Y"));

    return 0;
}
