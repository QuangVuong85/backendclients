/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef tpoststorage_TYPES_H
#define tpoststorage_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace OpenStars { namespace Common { namespace TPostStorageService {

struct TErrorCode {
  enum type {
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2,
    EDataExisted = -3
  };
};

extern const std::map<int, const char*> _TErrorCode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TErrorCode::type& val);

std::string to_string(const TErrorCode::type& val);

struct TPrivacy {
  enum type {
    Public = 0,
    Friends = 1,
    FriendsExcept = 2,
    Onlyme = 3,
    SpecificFriends = 4
  };
};

extern const std::map<int, const char*> _TPrivacy_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TPrivacy::type& val);

std::string to_string(const TPrivacy::type& val);

typedef int64_t TKey;

typedef class TPostItem TData;

class TPostItem;

class TDataResult;

class TListDataResult;

typedef struct _TPostItem__isset {
  _TPostItem__isset() : idpost(false), uid(false), content(false), listMediasId(false), idbackground(false), idfeeling(false), privacy(false), friendsexcept(false), specificfriends(false), tagusers(false), locationId(false), timestamps(false), pubkey(false) {}
  bool idpost :1;
  bool uid :1;
  bool content :1;
  bool listMediasId :1;
  bool idbackground :1;
  bool idfeeling :1;
  bool privacy :1;
  bool friendsexcept :1;
  bool specificfriends :1;
  bool tagusers :1;
  bool locationId :1;
  bool timestamps :1;
  bool pubkey :1;
} _TPostItem__isset;

class TPostItem : public virtual ::apache::thrift::TBase {
 public:

  TPostItem(const TPostItem&);
  TPostItem& operator=(const TPostItem&);
  TPostItem() : idpost(0), uid(0), content(), idbackground(), idfeeling(), privacy(0), locationId(), timestamps(0), pubkey() {
  }

  virtual ~TPostItem() noexcept;
  TKey idpost;
  int64_t uid;
  std::string content;
  std::vector<std::string>  listMediasId;
  std::string idbackground;
  std::string idfeeling;
  int64_t privacy;
  std::vector<int64_t>  friendsexcept;
  std::vector<int64_t>  specificfriends;
  std::vector<int64_t>  tagusers;
  std::string locationId;
  int64_t timestamps;
  std::string pubkey;

  _TPostItem__isset __isset;

  void __set_idpost(const TKey val);

  void __set_uid(const int64_t val);

  void __set_content(const std::string& val);

  void __set_listMediasId(const std::vector<std::string> & val);

  void __set_idbackground(const std::string& val);

  void __set_idfeeling(const std::string& val);

  void __set_privacy(const int64_t val);

  void __set_friendsexcept(const std::vector<int64_t> & val);

  void __set_specificfriends(const std::vector<int64_t> & val);

  void __set_tagusers(const std::vector<int64_t> & val);

  void __set_locationId(const std::string& val);

  void __set_timestamps(const int64_t val);

  void __set_pubkey(const std::string& val);

  bool operator == (const TPostItem & rhs) const
  {
    if (!(idpost == rhs.idpost))
      return false;
    if (!(uid == rhs.uid))
      return false;
    if (!(content == rhs.content))
      return false;
    if (__isset.listMediasId != rhs.__isset.listMediasId)
      return false;
    else if (__isset.listMediasId && !(listMediasId == rhs.listMediasId))
      return false;
    if (__isset.idbackground != rhs.__isset.idbackground)
      return false;
    else if (__isset.idbackground && !(idbackground == rhs.idbackground))
      return false;
    if (__isset.idfeeling != rhs.__isset.idfeeling)
      return false;
    else if (__isset.idfeeling && !(idfeeling == rhs.idfeeling))
      return false;
    if (!(privacy == rhs.privacy))
      return false;
    if (__isset.friendsexcept != rhs.__isset.friendsexcept)
      return false;
    else if (__isset.friendsexcept && !(friendsexcept == rhs.friendsexcept))
      return false;
    if (__isset.specificfriends != rhs.__isset.specificfriends)
      return false;
    else if (__isset.specificfriends && !(specificfriends == rhs.specificfriends))
      return false;
    if (__isset.tagusers != rhs.__isset.tagusers)
      return false;
    else if (__isset.tagusers && !(tagusers == rhs.tagusers))
      return false;
    if (__isset.locationId != rhs.__isset.locationId)
      return false;
    else if (__isset.locationId && !(locationId == rhs.locationId))
      return false;
    if (!(timestamps == rhs.timestamps))
      return false;
    if (!(pubkey == rhs.pubkey))
      return false;
    return true;
  }
  bool operator != (const TPostItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TPostItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPostItem &a, TPostItem &b);

std::ostream& operator<<(std::ostream& out, const TPostItem& obj);

typedef struct _TDataResult__isset {
  _TDataResult__isset() : errorCode(false), data(false) {}
  bool errorCode :1;
  bool data :1;
} _TDataResult__isset;

class TDataResult : public virtual ::apache::thrift::TBase {
 public:

  TDataResult(const TDataResult&);
  TDataResult& operator=(const TDataResult&);
  TDataResult() : errorCode((TErrorCode::type)0) {
  }

  virtual ~TDataResult() noexcept;
  TErrorCode::type errorCode;
  TPostItem data;

  _TDataResult__isset __isset;

  void __set_errorCode(const TErrorCode::type val);

  void __set_data(const TPostItem& val);

  bool operator == (const TDataResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.data != rhs.__isset.data)
      return false;
    else if (__isset.data && !(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const TDataResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDataResult &a, TDataResult &b);

std::ostream& operator<<(std::ostream& out, const TDataResult& obj);

typedef struct _TListDataResult__isset {
  _TListDataResult__isset() : errorCode(false), listDatas(false) {}
  bool errorCode :1;
  bool listDatas :1;
} _TListDataResult__isset;

class TListDataResult : public virtual ::apache::thrift::TBase {
 public:

  TListDataResult(const TListDataResult&);
  TListDataResult& operator=(const TListDataResult&);
  TListDataResult() : errorCode((TErrorCode::type)0) {
  }

  virtual ~TListDataResult() noexcept;
  TErrorCode::type errorCode;
  std::vector<TPostItem>  listDatas;

  _TListDataResult__isset __isset;

  void __set_errorCode(const TErrorCode::type val);

  void __set_listDatas(const std::vector<TPostItem> & val);

  bool operator == (const TListDataResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (!(listDatas == rhs.listDatas))
      return false;
    return true;
  }
  bool operator != (const TListDataResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TListDataResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TListDataResult &a, TListDataResult &b);

std::ostream& operator<<(std::ostream& out, const TListDataResult& obj);

}}} // namespace

#endif
