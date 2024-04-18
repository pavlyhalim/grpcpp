// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: file_exchange.proto

#include "file_exchange.pb.h"
#include "file_exchange.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace example {

static const char* FileExchange_method_names[] = {
  "/example.FileExchange/SendData",
  "/example.FileExchange/SendString",
  "/example.FileExchange/SendFile",
};

std::unique_ptr< FileExchange::Stub> FileExchange::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< FileExchange::Stub> stub(new FileExchange::Stub(channel, options));
  return stub;
}

FileExchange::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SendData_(FileExchange_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendString_(FileExchange_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendFile_(FileExchange_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  {}

::grpc::Status FileExchange::Stub::SendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::example::DataResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::example::DataRequest, ::example::DataResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendData_, context, request, response);
}

void FileExchange::Stub::async::SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::example::DataRequest, ::example::DataResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendData_, context, request, response, std::move(f));
}

void FileExchange::Stub::async::SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendData_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::example::DataResponse>* FileExchange::Stub::PrepareAsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::example::DataResponse, ::example::DataRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendData_, context, request);
}

::grpc::ClientAsyncResponseReader< ::example::DataResponse>* FileExchange::Stub::AsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendDataRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FileExchange::Stub::SendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::example::StringResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::example::StringRequest, ::example::StringResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendString_, context, request, response);
}

void FileExchange::Stub::async::SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::example::StringRequest, ::example::StringResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendString_, context, request, response, std::move(f));
}

void FileExchange::Stub::async::SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendString_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::example::StringResponse>* FileExchange::Stub::PrepareAsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::example::StringResponse, ::example::StringRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendString_, context, request);
}

::grpc::ClientAsyncResponseReader< ::example::StringResponse>* FileExchange::Stub::AsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendStringRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientWriter< ::example::FileChunk>* FileExchange::Stub::SendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::example::FileChunk>::Create(channel_.get(), rpcmethod_SendFile_, context, response);
}

void FileExchange::Stub::async::SendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::ClientWriteReactor< ::example::FileChunk>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::example::FileChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_SendFile_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::example::FileChunk>* FileExchange::Stub::AsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::example::FileChunk>::Create(channel_.get(), cq, rpcmethod_SendFile_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::example::FileChunk>* FileExchange::Stub::PrepareAsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::example::FileChunk>::Create(channel_.get(), cq, rpcmethod_SendFile_, context, response, false, nullptr);
}

FileExchange::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FileExchange_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FileExchange::Service, ::example::DataRequest, ::example::DataResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FileExchange::Service* service,
             ::grpc::ServerContext* ctx,
             const ::example::DataRequest* req,
             ::example::DataResponse* resp) {
               return service->SendData(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FileExchange_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FileExchange::Service, ::example::StringRequest, ::example::StringResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FileExchange::Service* service,
             ::grpc::ServerContext* ctx,
             const ::example::StringRequest* req,
             ::example::StringResponse* resp) {
               return service->SendString(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FileExchange_method_names[2],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< FileExchange::Service, ::example::FileChunk, ::example::FileResponse>(
          [](FileExchange::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::example::FileChunk>* reader,
             ::example::FileResponse* resp) {
               return service->SendFile(ctx, reader, resp);
             }, this)));
}

FileExchange::Service::~Service() {
}

::grpc::Status FileExchange::Service::SendData(::grpc::ServerContext* context, const ::example::DataRequest* request, ::example::DataResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FileExchange::Service::SendString(::grpc::ServerContext* context, const ::example::StringRequest* request, ::example::StringResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FileExchange::Service::SendFile(::grpc::ServerContext* context, ::grpc::ServerReader< ::example::FileChunk>* reader, ::example::FileResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace example
