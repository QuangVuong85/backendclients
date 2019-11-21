/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "i2skv_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace OpenStars { namespace Common { namespace MapPhoneNumberPubkeyKV {

int _kTErrorCodeValues[] = {
  TErrorCode::EGood,
  TErrorCode::ENotFound,
  TErrorCode::EUnknown,
  TErrorCode::EDataExisted
};
const char* _kTErrorCodeNames[] = {
  "EGood",
  "ENotFound",
  "EUnknown",
  "EDataExisted"
};
const std::map<int, const char*> _TErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kTErrorCodeValues, _kTErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TErrorCode::type& val) {
  std::map<int, const char*>::const_iterator it = _TErrorCode_VALUES_TO_NAMES.find(val);
  if (it != _TErrorCode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


TStringValue::~TStringValue() throw() {
}


void TStringValue::__set_value(const std::string& val) {
  this->value = val;
}
std::ostream& operator<<(std::ostream& out, const TStringValue& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TStringValue::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TStringValue::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TStringValue");

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TStringValue &a, TStringValue &b) {
  using ::std::swap;
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

TStringValue::TStringValue(const TStringValue& other0) {
  value = other0.value;
  __isset = other0.__isset;
}
TStringValue& TStringValue::operator=(const TStringValue& other1) {
  value = other1.value;
  __isset = other1.__isset;
  return *this;
}
void TStringValue::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TStringValue(";
  out << "value=" << to_string(value);
  out << ")";
}


TDataResult::~TDataResult() throw() {
}


void TDataResult::__set_errorCode(const TErrorCode::type val) {
  this->errorCode = val;
}

void TDataResult::__set_data(const TStringValue& val) {
  this->data = val;
__isset.data = true;
}
std::ostream& operator<<(std::ostream& out, const TDataResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TDataResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast2;
          xfer += iprot->readI32(ecast2);
          this->errorCode = (TErrorCode::type)ecast2;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TDataResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TDataResult");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.data) {
    xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->data.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TDataResult &a, TDataResult &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

TDataResult::TDataResult(const TDataResult& other3) {
  errorCode = other3.errorCode;
  data = other3.data;
  __isset = other3.__isset;
}
TDataResult& TDataResult::operator=(const TDataResult& other4) {
  errorCode = other4.errorCode;
  data = other4.data;
  __isset = other4.__isset;
  return *this;
}
void TDataResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDataResult(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "data="; (__isset.data ? (out << to_string(data)) : (out << "<null>"));
  out << ")";
}

}}} // namespace
