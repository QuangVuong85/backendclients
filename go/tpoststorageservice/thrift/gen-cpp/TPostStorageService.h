/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TPostStorageService_H
#define TPostStorageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "tpoststorage_types.h"
#include "TDataService.h"

namespace OpenStars { namespace Common { namespace TPostStorageService {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TPostStorageServiceIf : virtual public TDataServiceIf {
 public:
  virtual ~TPostStorageServiceIf() {}
};

class TPostStorageServiceIfFactory : virtual public TDataServiceIfFactory {
 public:
  typedef TPostStorageServiceIf Handler;

  virtual ~TPostStorageServiceIfFactory() {}

  virtual TPostStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TDataServiceIf* /* handler */) = 0;
};

class TPostStorageServiceIfSingletonFactory : virtual public TPostStorageServiceIfFactory {
 public:
  TPostStorageServiceIfSingletonFactory(const ::std::shared_ptr<TPostStorageServiceIf>& iface) : iface_(iface) {}
  virtual ~TPostStorageServiceIfSingletonFactory() {}

  virtual TPostStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TDataServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<TPostStorageServiceIf> iface_;
};

class TPostStorageServiceNull : virtual public TPostStorageServiceIf , virtual public TDataServiceNull {
 public:
  virtual ~TPostStorageServiceNull() {}
};

class TPostStorageServiceClient : virtual public TPostStorageServiceIf, public TDataServiceClient {
 public:
  TPostStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TDataServiceClient(prot, prot) {}
  TPostStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TDataServiceClient(iprot, oprot) {}
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
};

class TPostStorageServiceProcessor : public TDataServiceProcessor {
 protected:
  ::std::shared_ptr<TPostStorageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TPostStorageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
 public:
  TPostStorageServiceProcessor(::std::shared_ptr<TPostStorageServiceIf> iface) :
    TDataServiceProcessor(iface),
    iface_(iface) {
  }

  virtual ~TPostStorageServiceProcessor() {}
};

class TPostStorageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TPostStorageServiceProcessorFactory(const ::std::shared_ptr< TPostStorageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< TPostStorageServiceIfFactory > handlerFactory_;
};

class TPostStorageServiceMultiface : virtual public TPostStorageServiceIf, public TDataServiceMultiface {
 public:
  TPostStorageServiceMultiface(std::vector<std::shared_ptr<TPostStorageServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<std::shared_ptr<TPostStorageServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      TDataServiceMultiface::add(*iter);
    }
  }
  virtual ~TPostStorageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<TPostStorageServiceIf> > ifaces_;
  TPostStorageServiceMultiface() {}
  void add(::std::shared_ptr<TPostStorageServiceIf> iface) {
    TDataServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TPostStorageServiceConcurrentClient : virtual public TPostStorageServiceIf, public TDataServiceConcurrentClient {
 public:
  TPostStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) :
    TDataServiceConcurrentClient(prot, prot, sync) {}
  TPostStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) :    TDataServiceConcurrentClient(iprot, oprot, sync) {}
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif