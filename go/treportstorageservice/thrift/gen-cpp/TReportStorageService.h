/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TReportStorageService_H
#define TReportStorageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "treportstorage_types.h"
#include "TDataService.h"

namespace OpenStars { namespace Common { namespace TReportStorageService {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TReportStorageServiceIf : virtual public TDataServiceIf {
 public:
  virtual ~TReportStorageServiceIf() {}
};

class TReportStorageServiceIfFactory : virtual public TDataServiceIfFactory {
 public:
  typedef TReportStorageServiceIf Handler;

  virtual ~TReportStorageServiceIfFactory() {}

  virtual TReportStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TDataServiceIf* /* handler */) = 0;
};

class TReportStorageServiceIfSingletonFactory : virtual public TReportStorageServiceIfFactory {
 public:
  TReportStorageServiceIfSingletonFactory(const ::std::shared_ptr<TReportStorageServiceIf>& iface) : iface_(iface) {}
  virtual ~TReportStorageServiceIfSingletonFactory() {}

  virtual TReportStorageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TDataServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<TReportStorageServiceIf> iface_;
};

class TReportStorageServiceNull : virtual public TReportStorageServiceIf , virtual public TDataServiceNull {
 public:
  virtual ~TReportStorageServiceNull() {}
};

class TReportStorageServiceClient : virtual public TReportStorageServiceIf, public TDataServiceClient {
 public:
  TReportStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TDataServiceClient(prot, prot) {}
  TReportStorageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TDataServiceClient(iprot, oprot) {}
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
};

class TReportStorageServiceProcessor : public TDataServiceProcessor {
 protected:
  ::std::shared_ptr<TReportStorageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TReportStorageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
 public:
  TReportStorageServiceProcessor(::std::shared_ptr<TReportStorageServiceIf> iface) :
    TDataServiceProcessor(iface),
    iface_(iface) {
  }

  virtual ~TReportStorageServiceProcessor() {}
};

class TReportStorageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TReportStorageServiceProcessorFactory(const ::std::shared_ptr< TReportStorageServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< TReportStorageServiceIfFactory > handlerFactory_;
};

class TReportStorageServiceMultiface : virtual public TReportStorageServiceIf, public TDataServiceMultiface {
 public:
  TReportStorageServiceMultiface(std::vector<std::shared_ptr<TReportStorageServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<std::shared_ptr<TReportStorageServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      TDataServiceMultiface::add(*iter);
    }
  }
  virtual ~TReportStorageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<TReportStorageServiceIf> > ifaces_;
  TReportStorageServiceMultiface() {}
  void add(::std::shared_ptr<TReportStorageServiceIf> iface) {
    TDataServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TReportStorageServiceConcurrentClient : virtual public TReportStorageServiceIf, public TDataServiceConcurrentClient {
 public:
  TReportStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) :
    TDataServiceConcurrentClient(prot, prot, sync) {}
  TReportStorageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) :    TDataServiceConcurrentClient(iprot, oprot, sync) {}
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
