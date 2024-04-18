CXX = g++
CXXFLAGS = -std=c++17 \
           -I/opt/homebrew/Cellar/grpc/1.62.1_2/include \
           -I/opt/homebrew/Cellar/protobuf/26.1/include \
           -I/opt/homebrew/Cellar/abseil/20240116.2/include \
           -I/opt/homebrew/Cellar/googletest/1.14.0/include \
           -Iinclude \
           -pthread

ABSEIL_LIB_DIR = /opt/homebrew/Cellar/abseil/20240116.2/lib
ABSL_LIBS = $(shell find $(ABSEIL_LIB_DIR) -name 'libabsl_*.dylib' -exec basename {} \; | sed 's/lib//;s/.dylib//;s/^/-l/')

LDFLAGS = -L/opt/homebrew/Cellar/grpc/1.62.1_2/lib \
          -L/opt/homebrew/Cellar/protobuf/26.1/lib \
          -L/opt/homebrew/Cellar/abseil/20240116.2/lib \
          -L/opt/homebrew/Cellar/googletest/1.14.0/lib \
          -lgrpc++ -lgrpc -lgrpc++_reflection -lprotobuf -lgpr -lpthread -ldl \
          -lgtest -lgtest_main $(ABSL_LIBS)

PROTO_SRCS = src/file_exchange.pb.cc src/file_exchange.grpc.pb.cc
CATCH_SRC = src/catch_amalgamated.cpp

all: directories bin/client bin/server bin/main bin/tests/client_tests bin/tests/catch_tests

directories:
	@mkdir -p bin bin/tests obj obj/test

bin/client: obj/client.o $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) obj/client.o $(PROTO_SRCS) $(LDFLAGS) -o bin/client

bin/server: obj/server.o $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) obj/server.o $(PROTO_SRCS) $(LDFLAGS) -o bin/server

bin/main: obj/main.o obj/client.o $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) obj/main.o obj/client.o $(PROTO_SRCS) $(LDFLAGS) -o bin/main

bin/tests/client_tests: obj/test/client_tests.o obj/client.o $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) obj/test/client_tests.o obj/client.o $(PROTO_SRCS) $(LDFLAGS) -o bin/tests/client_tests

bin/tests/catch_tests: obj/test/catch_test.o obj/client.o $(PROTO_SRCS) obj/catch.o
	$(CXX) $(CXXFLAGS) obj/test/catch_test.o obj/client.o $(PROTO_SRCS) obj/catch.o $(LDFLAGS) -o bin/tests/catch_tests

obj/client.o: src/client.cpp include/client.h
	$(CXX) $(CXXFLAGS) -c src/client.cpp -o obj/client.o

obj/server.o: src/server.cpp
	$(CXX) $(CXXFLAGS) -c src/server.cpp -o obj/server.o

obj/main.o: src/main.cpp include/client.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o obj/main.o

obj/test/client_tests.o: test/client_tests.cpp include/client.h
	$(CXX) $(CXXFLAGS) -c test/client_tests.cpp -o obj/test/client_tests.o

obj/test/catch_test.o: test/catch_test.cpp include/catch_amalgamated.hpp include/client.h
	$(CXX) $(CXXFLAGS) -c test/catch_test.cpp -o obj/test/catch_test.o

obj/catch.o: src/catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -c src/catch_amalgamated.cpp -o obj/catch.o

clean:
	rm -rf bin/* bin/tests/* obj/* obj/test/*

.PHONY: all clean directories