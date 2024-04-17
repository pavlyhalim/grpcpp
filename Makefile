CXX = g++
CXXFLAGS = -std=c++17 \
           -I/opt/homebrew/Cellar/grpc/1.62.1_2/include \
           -I/opt/homebrew/Cellar/protobuf/26.1/include \
           -I/opt/homebrew/Cellar/abseil/20240116.2/include \
           -I/opt/homebrew/Cellar/googletest/1.14.0/include \
           -pthread

LDFLAGS = -L/opt/homebrew/Cellar/grpc/1.62.1_2/lib \
          -L/opt/homebrew/Cellar/protobuf/26.1/lib \
          -L/opt/homebrew/Cellar/abseil/20240116.2/lib \
          -L/opt/homebrew/Cellar/googletest/1.14.0/lib \
          -lgrpc++ -lgrpc -lgrpc++_reflection -lprotobuf -lgpr -lgtest -lgtest_main -lpthread -ldl

PROTO_SRCS = file_exchange.pb.cc file_exchange.grpc.pb.cc

all: client server client_tests

client: client.cpp $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) client.cpp $(PROTO_SRCS) $(LDFLAGS) -o client

server: server.cpp $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) server.cpp $(PROTO_SRCS) $(LDFLAGS) -o server

client_tests: client_tests.cpp $(PROTO_SRCS)
	$(CXX) $(CXXFLAGS) client_tests.cpp $(PROTO_SRCS) $(LDFLAGS) -o client_tests

clean:
	rm -f client server client_tests *.o

.PHONY: all clean