#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "client.h"
#include <iostream>
#include <string>

SCENARIO("FileExchangeClient sends data correctly", "[FileExchangeClient]") {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    FileExchangeClient client(channel);

    GIVEN("A valid integer number") {
        std::string number = "123";

        WHEN("the client sends this number") {
            bool result = client.SendData(number);

            THEN("the result should be true") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN("An out-of-range integer number") {
        std::string overflowNumber = std::to_string(INT64_MAX) + "0";

        WHEN("the client sends this number") {
            bool result = client.SendData(overflowNumber);

            THEN("the result should be false") {
                REQUIRE(result == false);
            }
        }
    }

    GIVEN("A valid string of maximum allowed length") {
        std::string maxLengthString(1024, 'a');

        WHEN("the client sends this string") {
            bool result = client.SendString(maxLengthString);

            THEN("the result should be true") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN("An empty string") {
        std::string emptyString = "";

        WHEN("the client sends this string") {
            bool result = client.SendString(emptyString);

            THEN("the result should be true") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN("A string with special characters") {
        std::string specialCharsString = "Hello, \nWorld!@#$$%^&*()";

        WHEN("the client sends this string") {
            bool result = client.SendString(specialCharsString);

            THEN("the result should be true") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN("A valid file path") {
        std::string filePath = "path/test/test.mp4";

        WHEN("the client sends this file") {
            bool result = client.SendFile(filePath);

            THEN("the result should be true") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN("A non-existent file path") {
        std::string nonExistentFilePath = "/path/that/does/not/exist.mp4";

        WHEN("the client sends this file") {
            bool result = client.SendFile(nonExistentFilePath);

            THEN("the result should be false") {
                REQUIRE(result == false);
            }
        }
    }
}