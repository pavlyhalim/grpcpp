// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: file_exchange.proto
#ifndef GRPC_file_5fexchange_2eproto__INCLUDED
#define GRPC_file_5fexchange_2eproto__INCLUDED

#include "file_exchange.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace example {

class FileExchange final {
 public:
  static constexpr char const* service_full_name() {
    return "example.FileExchange";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::example::DataResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>> AsyncSendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>>(AsyncSendDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>> PrepareAsyncSendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>>(PrepareAsyncSendDataRaw(context, request, cq));
    }
    virtual ::grpc::Status SendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::example::StringResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>> AsyncSendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>>(AsyncSendStringRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>> PrepareAsyncSendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>>(PrepareAsyncSendStringRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientWriterInterface< ::example::FileChunk>> SendFile(::grpc::ClientContext* context, ::example::FileResponse* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::example::FileChunk>>(SendFileRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>> AsyncSendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>>(AsyncSendFileRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>> PrepareAsyncSendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>>(PrepareAsyncSendFileRaw(context, response, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void SendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::ClientWriteReactor< ::example::FileChunk>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>* AsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::example::DataResponse>* PrepareAsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>* AsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::example::StringResponse>* PrepareAsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientWriterInterface< ::example::FileChunk>* SendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>* AsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::example::FileChunk>* PrepareAsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status SendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::example::DataResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::DataResponse>> AsyncSendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::DataResponse>>(AsyncSendDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::DataResponse>> PrepareAsyncSendData(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::DataResponse>>(PrepareAsyncSendDataRaw(context, request, cq));
    }
    ::grpc::Status SendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::example::StringResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::StringResponse>> AsyncSendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::StringResponse>>(AsyncSendStringRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::StringResponse>> PrepareAsyncSendString(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::example::StringResponse>>(PrepareAsyncSendStringRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientWriter< ::example::FileChunk>> SendFile(::grpc::ClientContext* context, ::example::FileResponse* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::example::FileChunk>>(SendFileRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::example::FileChunk>> AsyncSendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::example::FileChunk>>(AsyncSendFileRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::example::FileChunk>> PrepareAsyncSendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::example::FileChunk>>(PrepareAsyncSendFileRaw(context, response, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, std::function<void(::grpc::Status)>) override;
      void SendData(::grpc::ClientContext* context, const ::example::DataRequest* request, ::example::DataResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, std::function<void(::grpc::Status)>) override;
      void SendString(::grpc::ClientContext* context, const ::example::StringRequest* request, ::example::StringResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void SendFile(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::ClientWriteReactor< ::example::FileChunk>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::example::DataResponse>* AsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::example::DataResponse>* PrepareAsyncSendDataRaw(::grpc::ClientContext* context, const ::example::DataRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::example::StringResponse>* AsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::example::StringResponse>* PrepareAsyncSendStringRaw(::grpc::ClientContext* context, const ::example::StringRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientWriter< ::example::FileChunk>* SendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response) override;
    ::grpc::ClientAsyncWriter< ::example::FileChunk>* AsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::example::FileChunk>* PrepareAsyncSendFileRaw(::grpc::ClientContext* context, ::example::FileResponse* response, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SendData_;
    const ::grpc::internal::RpcMethod rpcmethod_SendString_;
    const ::grpc::internal::RpcMethod rpcmethod_SendFile_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status SendData(::grpc::ServerContext* context, const ::example::DataRequest* request, ::example::DataResponse* response);
    virtual ::grpc::Status SendString(::grpc::ServerContext* context, const ::example::StringRequest* request, ::example::StringResponse* response);
    virtual ::grpc::Status SendFile(::grpc::ServerContext* context, ::grpc::ServerReader< ::example::FileChunk>* reader, ::example::FileResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendData() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendData(::grpc::ServerContext* context, ::example::DataRequest* request, ::grpc::ServerAsyncResponseWriter< ::example::DataResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendString() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendString(::grpc::ServerContext* context, ::example::StringRequest* request, ::grpc::ServerAsyncResponseWriter< ::example::StringResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendFile() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_SendFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendFile(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::example::FileChunk>* /*reader*/, ::example::FileResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendFile(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::example::FileResponse, ::example::FileChunk>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SendData<WithAsyncMethod_SendString<WithAsyncMethod_SendFile<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SendData() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::example::DataRequest, ::example::DataResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::example::DataRequest* request, ::example::DataResponse* response) { return this->SendData(context, request, response); }));}
    void SetMessageAllocatorFor_SendData(
        ::grpc::MessageAllocator< ::example::DataRequest, ::example::DataResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::example::DataRequest, ::example::DataResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendData(
      ::grpc::CallbackServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SendString() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::example::StringRequest, ::example::StringResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::example::StringRequest* request, ::example::StringResponse* response) { return this->SendString(context, request, response); }));}
    void SetMessageAllocatorFor_SendString(
        ::grpc::MessageAllocator< ::example::StringRequest, ::example::StringResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::example::StringRequest, ::example::StringResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendString(
      ::grpc::CallbackServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_SendFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SendFile() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackClientStreamingHandler< ::example::FileChunk, ::example::FileResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, ::example::FileResponse* response) { return this->SendFile(context, response); }));
    }
    ~WithCallbackMethod_SendFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendFile(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::example::FileChunk>* /*reader*/, ::example::FileResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::example::FileChunk>* SendFile(
      ::grpc::CallbackServerContext* /*context*/, ::example::FileResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_SendData<WithCallbackMethod_SendString<WithCallbackMethod_SendFile<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendData() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendString() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendFile() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_SendFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendFile(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::example::FileChunk>* /*reader*/, ::example::FileResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendData() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendData(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendString() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendString(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendFile() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_SendFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendFile(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::example::FileChunk>* /*reader*/, ::example::FileResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendFile(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SendData() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendData(context, request, response); }));
    }
    ~WithRawCallbackMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendData(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SendString() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendString(context, request, response); }));
    }
    ~WithRawCallbackMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendString(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SendFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SendFile() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, ::grpc::ByteBuffer* response) { return this->SendFile(context, response); }));
    }
    ~WithRawCallbackMethod_SendFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendFile(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::example::FileChunk>* /*reader*/, ::example::FileResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* SendFile(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendData() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::example::DataRequest, ::example::DataResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::example::DataRequest, ::example::DataResponse>* streamer) {
                       return this->StreamedSendData(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendData(::grpc::ServerContext* /*context*/, const ::example::DataRequest* /*request*/, ::example::DataResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendData(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::example::DataRequest,::example::DataResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendString : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendString() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::example::StringRequest, ::example::StringResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::example::StringRequest, ::example::StringResponse>* streamer) {
                       return this->StreamedSendString(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendString() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendString(::grpc::ServerContext* /*context*/, const ::example::StringRequest* /*request*/, ::example::StringResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendString(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::example::StringRequest,::example::StringResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SendData<WithStreamedUnaryMethod_SendString<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SendData<WithStreamedUnaryMethod_SendString<Service > > StreamedService;
};

}  // namespace example


#endif  // GRPC_file_5fexchange_2eproto__INCLUDED