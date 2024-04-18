#include "client.h"
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

//Helper class to manage tests
class TestManager {
public:
    using TestFunc = std::function<void()>;
    
    void addTest(const std::string& testName, TestFunc func) {
        tests.push_back({testName, func});
    }

    void runTests() {
        int passed = 0;
        for (auto& test : tests) {
            std::cout << "Running " << test.first << "..." << std::endl;
            try {
                test.second();
                std::cout << test.first << " Passed." << std::endl;
                ++passed;
            } catch (const std::exception& e) {
                std::cerr << test.first << " Failed: " << e.what() << std::endl;
            }
        }
        std::cout << "Summary: " << passed << "/" << tests.size() << " tests passed." << std::endl;
    }

private:
    std::vector<std::pair<std::string, TestFunc>> tests;
};

//throw on failure
void assertTest(bool condition, const std::string& message) {
    if (!condition) throw std::runtime_error(message);
}

//Test functions
void testSendData(FileExchangeClient& client) {
    bool result = client.SendData(std::to_string(123));
    assertTest(result, "SendData should succeed with valid number.");
}

void testSendDataFailure(FileExchangeClient& client) {
    //overflow
    std::string overflowNumber = std::to_string(INT64_MAX) + "0";
    bool result = client.SendData(overflowNumber);
    assertTest(!result, "SendData should fail when number is out of range.");
}

void testSendString(FileExchangeClient& client) {
    bool result = client.SendString("Hello, World!");
    assertTest(result, "SendString should succeed with valid string.");
}

void testSendFile(FileExchangeClient& client) {
    bool result = client.SendFile("/path/test/file.txt");
    assertTest(result, "SendFile should succeed with valid file path.");
}

int main() {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    FileExchangeClient client(channel);

    TestManager manager;
    manager.addTest("Test SendData Success", [&]() { testSendData(client); });
    manager.addTest("Test SendData Failure", [&]() { testSendDataFailure(client); });
    manager.addTest("Test SendString Success", [&]() { testSendString(client); });
    manager.addTest("Test SendFile Success", [&]() { testSendFile(client); });
    manager.runTests();
    return 0;
}
