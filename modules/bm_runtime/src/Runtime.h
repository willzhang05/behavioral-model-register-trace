/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Runtime_H
#define Runtime_H

#include <thrift/TDispatchProcessor.h>
#include "runtime_types.h"

namespace bm_runtime {

class RuntimeIf {
 public:
  virtual ~RuntimeIf() {}
  virtual BmEntryHandle bm_table_add_exact_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmActionData& action_data) = 0;
  virtual BmEntryHandle bm_table_add_lpm_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const int32_t prefix_length, const BmActionData& action_data) = 0;
  virtual BmEntryHandle bm_table_add_ternary_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmMatchKey& match_mask, const int32_t priority, const BmActionData& action_data) = 0;
  virtual void bm_set_default_action(const std::string& table_name, const std::string& action_name, const BmActionData& action_data) = 0;
  virtual void bm_table_delete_entry(const std::string& table_name, const BmEntryHandle entry_handle) = 0;
  virtual void bm_learning_ack(const BmLearningListId list_id, const BmLearningBufferId buffer_id, const std::vector<BmLearningSampleId> & sample_ids) = 0;
  virtual void bm_learning_ack_buffer(const BmLearningListId list_id, const BmLearningBufferId buffer_id) = 0;
};

class RuntimeIfFactory {
 public:
  typedef RuntimeIf Handler;

  virtual ~RuntimeIfFactory() {}

  virtual RuntimeIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RuntimeIf* /* handler */) = 0;
};

class RuntimeIfSingletonFactory : virtual public RuntimeIfFactory {
 public:
  RuntimeIfSingletonFactory(const boost::shared_ptr<RuntimeIf>& iface) : iface_(iface) {}
  virtual ~RuntimeIfSingletonFactory() {}

  virtual RuntimeIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RuntimeIf* /* handler */) {}

 protected:
  boost::shared_ptr<RuntimeIf> iface_;
};

class RuntimeNull : virtual public RuntimeIf {
 public:
  virtual ~RuntimeNull() {}
  BmEntryHandle bm_table_add_exact_match_entry(const std::string& /* table_name */, const std::string& /* action_name */, const BmMatchKey& /* match_key */, const BmActionData& /* action_data */) {
    BmEntryHandle _return = 0;
    return _return;
  }
  BmEntryHandle bm_table_add_lpm_entry(const std::string& /* table_name */, const std::string& /* action_name */, const BmMatchKey& /* match_key */, const int32_t /* prefix_length */, const BmActionData& /* action_data */) {
    BmEntryHandle _return = 0;
    return _return;
  }
  BmEntryHandle bm_table_add_ternary_match_entry(const std::string& /* table_name */, const std::string& /* action_name */, const BmMatchKey& /* match_key */, const BmMatchKey& /* match_mask */, const int32_t /* priority */, const BmActionData& /* action_data */) {
    BmEntryHandle _return = 0;
    return _return;
  }
  void bm_set_default_action(const std::string& /* table_name */, const std::string& /* action_name */, const BmActionData& /* action_data */) {
    return;
  }
  void bm_table_delete_entry(const std::string& /* table_name */, const BmEntryHandle /* entry_handle */) {
    return;
  }
  void bm_learning_ack(const BmLearningListId /* list_id */, const BmLearningBufferId /* buffer_id */, const std::vector<BmLearningSampleId> & /* sample_ids */) {
    return;
  }
  void bm_learning_ack_buffer(const BmLearningListId /* list_id */, const BmLearningBufferId /* buffer_id */) {
    return;
  }
};

typedef struct _Runtime_bm_table_add_exact_match_entry_args__isset {
  _Runtime_bm_table_add_exact_match_entry_args__isset() : table_name(false), action_name(false), match_key(false), action_data(false) {}
  bool table_name;
  bool action_name;
  bool match_key;
  bool action_data;
} _Runtime_bm_table_add_exact_match_entry_args__isset;

class Runtime_bm_table_add_exact_match_entry_args {
 public:

  Runtime_bm_table_add_exact_match_entry_args() : table_name(), action_name() {
  }

  virtual ~Runtime_bm_table_add_exact_match_entry_args() throw() {}

  std::string table_name;
  std::string action_name;
  BmMatchKey match_key;
  BmActionData action_data;

  _Runtime_bm_table_add_exact_match_entry_args__isset __isset;

  void __set_table_name(const std::string& val) {
    table_name = val;
  }

  void __set_action_name(const std::string& val) {
    action_name = val;
  }

  void __set_match_key(const BmMatchKey& val) {
    match_key = val;
  }

  void __set_action_data(const BmActionData& val) {
    action_data = val;
  }

  bool operator == (const Runtime_bm_table_add_exact_match_entry_args & rhs) const
  {
    if (!(table_name == rhs.table_name))
      return false;
    if (!(action_name == rhs.action_name))
      return false;
    if (!(match_key == rhs.match_key))
      return false;
    if (!(action_data == rhs.action_data))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_exact_match_entry_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_exact_match_entry_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_table_add_exact_match_entry_pargs {
 public:


  virtual ~Runtime_bm_table_add_exact_match_entry_pargs() throw() {}

  const std::string* table_name;
  const std::string* action_name;
  const BmMatchKey* match_key;
  const BmActionData* action_data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_exact_match_entry_result__isset {
  _Runtime_bm_table_add_exact_match_entry_result__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_exact_match_entry_result__isset;

class Runtime_bm_table_add_exact_match_entry_result {
 public:

  Runtime_bm_table_add_exact_match_entry_result() : success(0) {
  }

  virtual ~Runtime_bm_table_add_exact_match_entry_result() throw() {}

  BmEntryHandle success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_exact_match_entry_result__isset __isset;

  void __set_success(const BmEntryHandle val) {
    success = val;
  }

  void __set_ouch(const InvalidTableOperation& val) {
    ouch = val;
  }

  bool operator == (const Runtime_bm_table_add_exact_match_entry_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_exact_match_entry_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_exact_match_entry_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_exact_match_entry_presult__isset {
  _Runtime_bm_table_add_exact_match_entry_presult__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_exact_match_entry_presult__isset;

class Runtime_bm_table_add_exact_match_entry_presult {
 public:


  virtual ~Runtime_bm_table_add_exact_match_entry_presult() throw() {}

  BmEntryHandle* success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_exact_match_entry_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_table_add_lpm_entry_args__isset {
  _Runtime_bm_table_add_lpm_entry_args__isset() : table_name(false), action_name(false), match_key(false), prefix_length(false), action_data(false) {}
  bool table_name;
  bool action_name;
  bool match_key;
  bool prefix_length;
  bool action_data;
} _Runtime_bm_table_add_lpm_entry_args__isset;

class Runtime_bm_table_add_lpm_entry_args {
 public:

  Runtime_bm_table_add_lpm_entry_args() : table_name(), action_name(), prefix_length(0) {
  }

  virtual ~Runtime_bm_table_add_lpm_entry_args() throw() {}

  std::string table_name;
  std::string action_name;
  BmMatchKey match_key;
  int32_t prefix_length;
  BmActionData action_data;

  _Runtime_bm_table_add_lpm_entry_args__isset __isset;

  void __set_table_name(const std::string& val) {
    table_name = val;
  }

  void __set_action_name(const std::string& val) {
    action_name = val;
  }

  void __set_match_key(const BmMatchKey& val) {
    match_key = val;
  }

  void __set_prefix_length(const int32_t val) {
    prefix_length = val;
  }

  void __set_action_data(const BmActionData& val) {
    action_data = val;
  }

  bool operator == (const Runtime_bm_table_add_lpm_entry_args & rhs) const
  {
    if (!(table_name == rhs.table_name))
      return false;
    if (!(action_name == rhs.action_name))
      return false;
    if (!(match_key == rhs.match_key))
      return false;
    if (!(prefix_length == rhs.prefix_length))
      return false;
    if (!(action_data == rhs.action_data))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_lpm_entry_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_lpm_entry_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_table_add_lpm_entry_pargs {
 public:


  virtual ~Runtime_bm_table_add_lpm_entry_pargs() throw() {}

  const std::string* table_name;
  const std::string* action_name;
  const BmMatchKey* match_key;
  const int32_t* prefix_length;
  const BmActionData* action_data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_lpm_entry_result__isset {
  _Runtime_bm_table_add_lpm_entry_result__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_lpm_entry_result__isset;

class Runtime_bm_table_add_lpm_entry_result {
 public:

  Runtime_bm_table_add_lpm_entry_result() : success(0) {
  }

  virtual ~Runtime_bm_table_add_lpm_entry_result() throw() {}

  BmEntryHandle success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_lpm_entry_result__isset __isset;

  void __set_success(const BmEntryHandle val) {
    success = val;
  }

  void __set_ouch(const InvalidTableOperation& val) {
    ouch = val;
  }

  bool operator == (const Runtime_bm_table_add_lpm_entry_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_lpm_entry_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_lpm_entry_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_lpm_entry_presult__isset {
  _Runtime_bm_table_add_lpm_entry_presult__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_lpm_entry_presult__isset;

class Runtime_bm_table_add_lpm_entry_presult {
 public:


  virtual ~Runtime_bm_table_add_lpm_entry_presult() throw() {}

  BmEntryHandle* success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_lpm_entry_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_table_add_ternary_match_entry_args__isset {
  _Runtime_bm_table_add_ternary_match_entry_args__isset() : table_name(false), action_name(false), match_key(false), match_mask(false), priority(false), action_data(false) {}
  bool table_name;
  bool action_name;
  bool match_key;
  bool match_mask;
  bool priority;
  bool action_data;
} _Runtime_bm_table_add_ternary_match_entry_args__isset;

class Runtime_bm_table_add_ternary_match_entry_args {
 public:

  Runtime_bm_table_add_ternary_match_entry_args() : table_name(), action_name(), priority(0) {
  }

  virtual ~Runtime_bm_table_add_ternary_match_entry_args() throw() {}

  std::string table_name;
  std::string action_name;
  BmMatchKey match_key;
  BmMatchKey match_mask;
  int32_t priority;
  BmActionData action_data;

  _Runtime_bm_table_add_ternary_match_entry_args__isset __isset;

  void __set_table_name(const std::string& val) {
    table_name = val;
  }

  void __set_action_name(const std::string& val) {
    action_name = val;
  }

  void __set_match_key(const BmMatchKey& val) {
    match_key = val;
  }

  void __set_match_mask(const BmMatchKey& val) {
    match_mask = val;
  }

  void __set_priority(const int32_t val) {
    priority = val;
  }

  void __set_action_data(const BmActionData& val) {
    action_data = val;
  }

  bool operator == (const Runtime_bm_table_add_ternary_match_entry_args & rhs) const
  {
    if (!(table_name == rhs.table_name))
      return false;
    if (!(action_name == rhs.action_name))
      return false;
    if (!(match_key == rhs.match_key))
      return false;
    if (!(match_mask == rhs.match_mask))
      return false;
    if (!(priority == rhs.priority))
      return false;
    if (!(action_data == rhs.action_data))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_ternary_match_entry_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_ternary_match_entry_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_table_add_ternary_match_entry_pargs {
 public:


  virtual ~Runtime_bm_table_add_ternary_match_entry_pargs() throw() {}

  const std::string* table_name;
  const std::string* action_name;
  const BmMatchKey* match_key;
  const BmMatchKey* match_mask;
  const int32_t* priority;
  const BmActionData* action_data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_ternary_match_entry_result__isset {
  _Runtime_bm_table_add_ternary_match_entry_result__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_ternary_match_entry_result__isset;

class Runtime_bm_table_add_ternary_match_entry_result {
 public:

  Runtime_bm_table_add_ternary_match_entry_result() : success(0) {
  }

  virtual ~Runtime_bm_table_add_ternary_match_entry_result() throw() {}

  BmEntryHandle success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_ternary_match_entry_result__isset __isset;

  void __set_success(const BmEntryHandle val) {
    success = val;
  }

  void __set_ouch(const InvalidTableOperation& val) {
    ouch = val;
  }

  bool operator == (const Runtime_bm_table_add_ternary_match_entry_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_add_ternary_match_entry_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_add_ternary_match_entry_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_add_ternary_match_entry_presult__isset {
  _Runtime_bm_table_add_ternary_match_entry_presult__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _Runtime_bm_table_add_ternary_match_entry_presult__isset;

class Runtime_bm_table_add_ternary_match_entry_presult {
 public:


  virtual ~Runtime_bm_table_add_ternary_match_entry_presult() throw() {}

  BmEntryHandle* success;
  InvalidTableOperation ouch;

  _Runtime_bm_table_add_ternary_match_entry_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_set_default_action_args__isset {
  _Runtime_bm_set_default_action_args__isset() : table_name(false), action_name(false), action_data(false) {}
  bool table_name;
  bool action_name;
  bool action_data;
} _Runtime_bm_set_default_action_args__isset;

class Runtime_bm_set_default_action_args {
 public:

  Runtime_bm_set_default_action_args() : table_name(), action_name() {
  }

  virtual ~Runtime_bm_set_default_action_args() throw() {}

  std::string table_name;
  std::string action_name;
  BmActionData action_data;

  _Runtime_bm_set_default_action_args__isset __isset;

  void __set_table_name(const std::string& val) {
    table_name = val;
  }

  void __set_action_name(const std::string& val) {
    action_name = val;
  }

  void __set_action_data(const BmActionData& val) {
    action_data = val;
  }

  bool operator == (const Runtime_bm_set_default_action_args & rhs) const
  {
    if (!(table_name == rhs.table_name))
      return false;
    if (!(action_name == rhs.action_name))
      return false;
    if (!(action_data == rhs.action_data))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_set_default_action_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_set_default_action_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_set_default_action_pargs {
 public:


  virtual ~Runtime_bm_set_default_action_pargs() throw() {}

  const std::string* table_name;
  const std::string* action_name;
  const BmActionData* action_data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_set_default_action_result__isset {
  _Runtime_bm_set_default_action_result__isset() : ouch(false) {}
  bool ouch;
} _Runtime_bm_set_default_action_result__isset;

class Runtime_bm_set_default_action_result {
 public:

  Runtime_bm_set_default_action_result() {
  }

  virtual ~Runtime_bm_set_default_action_result() throw() {}

  InvalidTableOperation ouch;

  _Runtime_bm_set_default_action_result__isset __isset;

  void __set_ouch(const InvalidTableOperation& val) {
    ouch = val;
  }

  bool operator == (const Runtime_bm_set_default_action_result & rhs) const
  {
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_set_default_action_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_set_default_action_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_set_default_action_presult__isset {
  _Runtime_bm_set_default_action_presult__isset() : ouch(false) {}
  bool ouch;
} _Runtime_bm_set_default_action_presult__isset;

class Runtime_bm_set_default_action_presult {
 public:


  virtual ~Runtime_bm_set_default_action_presult() throw() {}

  InvalidTableOperation ouch;

  _Runtime_bm_set_default_action_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_table_delete_entry_args__isset {
  _Runtime_bm_table_delete_entry_args__isset() : table_name(false), entry_handle(false) {}
  bool table_name;
  bool entry_handle;
} _Runtime_bm_table_delete_entry_args__isset;

class Runtime_bm_table_delete_entry_args {
 public:

  Runtime_bm_table_delete_entry_args() : table_name(), entry_handle(0) {
  }

  virtual ~Runtime_bm_table_delete_entry_args() throw() {}

  std::string table_name;
  BmEntryHandle entry_handle;

  _Runtime_bm_table_delete_entry_args__isset __isset;

  void __set_table_name(const std::string& val) {
    table_name = val;
  }

  void __set_entry_handle(const BmEntryHandle val) {
    entry_handle = val;
  }

  bool operator == (const Runtime_bm_table_delete_entry_args & rhs) const
  {
    if (!(table_name == rhs.table_name))
      return false;
    if (!(entry_handle == rhs.entry_handle))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_delete_entry_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_delete_entry_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_table_delete_entry_pargs {
 public:


  virtual ~Runtime_bm_table_delete_entry_pargs() throw() {}

  const std::string* table_name;
  const BmEntryHandle* entry_handle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_delete_entry_result__isset {
  _Runtime_bm_table_delete_entry_result__isset() : ouch(false) {}
  bool ouch;
} _Runtime_bm_table_delete_entry_result__isset;

class Runtime_bm_table_delete_entry_result {
 public:

  Runtime_bm_table_delete_entry_result() {
  }

  virtual ~Runtime_bm_table_delete_entry_result() throw() {}

  InvalidTableOperation ouch;

  _Runtime_bm_table_delete_entry_result__isset __isset;

  void __set_ouch(const InvalidTableOperation& val) {
    ouch = val;
  }

  bool operator == (const Runtime_bm_table_delete_entry_result & rhs) const
  {
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_table_delete_entry_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_table_delete_entry_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Runtime_bm_table_delete_entry_presult__isset {
  _Runtime_bm_table_delete_entry_presult__isset() : ouch(false) {}
  bool ouch;
} _Runtime_bm_table_delete_entry_presult__isset;

class Runtime_bm_table_delete_entry_presult {
 public:


  virtual ~Runtime_bm_table_delete_entry_presult() throw() {}

  InvalidTableOperation ouch;

  _Runtime_bm_table_delete_entry_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_learning_ack_args__isset {
  _Runtime_bm_learning_ack_args__isset() : list_id(false), buffer_id(false), sample_ids(false) {}
  bool list_id;
  bool buffer_id;
  bool sample_ids;
} _Runtime_bm_learning_ack_args__isset;

class Runtime_bm_learning_ack_args {
 public:

  Runtime_bm_learning_ack_args() : list_id(0), buffer_id(0) {
  }

  virtual ~Runtime_bm_learning_ack_args() throw() {}

  BmLearningListId list_id;
  BmLearningBufferId buffer_id;
  std::vector<BmLearningSampleId>  sample_ids;

  _Runtime_bm_learning_ack_args__isset __isset;

  void __set_list_id(const BmLearningListId val) {
    list_id = val;
  }

  void __set_buffer_id(const BmLearningBufferId val) {
    buffer_id = val;
  }

  void __set_sample_ids(const std::vector<BmLearningSampleId> & val) {
    sample_ids = val;
  }

  bool operator == (const Runtime_bm_learning_ack_args & rhs) const
  {
    if (!(list_id == rhs.list_id))
      return false;
    if (!(buffer_id == rhs.buffer_id))
      return false;
    if (!(sample_ids == rhs.sample_ids))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_learning_ack_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_learning_ack_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_pargs {
 public:


  virtual ~Runtime_bm_learning_ack_pargs() throw() {}

  const BmLearningListId* list_id;
  const BmLearningBufferId* buffer_id;
  const std::vector<BmLearningSampleId> * sample_ids;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_result {
 public:

  Runtime_bm_learning_ack_result() {
  }

  virtual ~Runtime_bm_learning_ack_result() throw() {}


  bool operator == (const Runtime_bm_learning_ack_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Runtime_bm_learning_ack_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_learning_ack_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_presult {
 public:


  virtual ~Runtime_bm_learning_ack_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Runtime_bm_learning_ack_buffer_args__isset {
  _Runtime_bm_learning_ack_buffer_args__isset() : list_id(false), buffer_id(false) {}
  bool list_id;
  bool buffer_id;
} _Runtime_bm_learning_ack_buffer_args__isset;

class Runtime_bm_learning_ack_buffer_args {
 public:

  Runtime_bm_learning_ack_buffer_args() : list_id(0), buffer_id(0) {
  }

  virtual ~Runtime_bm_learning_ack_buffer_args() throw() {}

  BmLearningListId list_id;
  BmLearningBufferId buffer_id;

  _Runtime_bm_learning_ack_buffer_args__isset __isset;

  void __set_list_id(const BmLearningListId val) {
    list_id = val;
  }

  void __set_buffer_id(const BmLearningBufferId val) {
    buffer_id = val;
  }

  bool operator == (const Runtime_bm_learning_ack_buffer_args & rhs) const
  {
    if (!(list_id == rhs.list_id))
      return false;
    if (!(buffer_id == rhs.buffer_id))
      return false;
    return true;
  }
  bool operator != (const Runtime_bm_learning_ack_buffer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_learning_ack_buffer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_buffer_pargs {
 public:


  virtual ~Runtime_bm_learning_ack_buffer_pargs() throw() {}

  const BmLearningListId* list_id;
  const BmLearningBufferId* buffer_id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_buffer_result {
 public:

  Runtime_bm_learning_ack_buffer_result() {
  }

  virtual ~Runtime_bm_learning_ack_buffer_result() throw() {}


  bool operator == (const Runtime_bm_learning_ack_buffer_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Runtime_bm_learning_ack_buffer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Runtime_bm_learning_ack_buffer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Runtime_bm_learning_ack_buffer_presult {
 public:


  virtual ~Runtime_bm_learning_ack_buffer_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RuntimeClient : virtual public RuntimeIf {
 public:
  RuntimeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  RuntimeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  BmEntryHandle bm_table_add_exact_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmActionData& action_data);
  void send_bm_table_add_exact_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmActionData& action_data);
  BmEntryHandle recv_bm_table_add_exact_match_entry();
  BmEntryHandle bm_table_add_lpm_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const int32_t prefix_length, const BmActionData& action_data);
  void send_bm_table_add_lpm_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const int32_t prefix_length, const BmActionData& action_data);
  BmEntryHandle recv_bm_table_add_lpm_entry();
  BmEntryHandle bm_table_add_ternary_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmMatchKey& match_mask, const int32_t priority, const BmActionData& action_data);
  void send_bm_table_add_ternary_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmMatchKey& match_mask, const int32_t priority, const BmActionData& action_data);
  BmEntryHandle recv_bm_table_add_ternary_match_entry();
  void bm_set_default_action(const std::string& table_name, const std::string& action_name, const BmActionData& action_data);
  void send_bm_set_default_action(const std::string& table_name, const std::string& action_name, const BmActionData& action_data);
  void recv_bm_set_default_action();
  void bm_table_delete_entry(const std::string& table_name, const BmEntryHandle entry_handle);
  void send_bm_table_delete_entry(const std::string& table_name, const BmEntryHandle entry_handle);
  void recv_bm_table_delete_entry();
  void bm_learning_ack(const BmLearningListId list_id, const BmLearningBufferId buffer_id, const std::vector<BmLearningSampleId> & sample_ids);
  void send_bm_learning_ack(const BmLearningListId list_id, const BmLearningBufferId buffer_id, const std::vector<BmLearningSampleId> & sample_ids);
  void recv_bm_learning_ack();
  void bm_learning_ack_buffer(const BmLearningListId list_id, const BmLearningBufferId buffer_id);
  void send_bm_learning_ack_buffer(const BmLearningListId list_id, const BmLearningBufferId buffer_id);
  void recv_bm_learning_ack_buffer();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RuntimeProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<RuntimeIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RuntimeProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_bm_table_add_exact_match_entry(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_table_add_lpm_entry(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_table_add_ternary_match_entry(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_set_default_action(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_table_delete_entry(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_learning_ack(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_bm_learning_ack_buffer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RuntimeProcessor(boost::shared_ptr<RuntimeIf> iface) :
    iface_(iface) {
    processMap_["bm_table_add_exact_match_entry"] = &RuntimeProcessor::process_bm_table_add_exact_match_entry;
    processMap_["bm_table_add_lpm_entry"] = &RuntimeProcessor::process_bm_table_add_lpm_entry;
    processMap_["bm_table_add_ternary_match_entry"] = &RuntimeProcessor::process_bm_table_add_ternary_match_entry;
    processMap_["bm_set_default_action"] = &RuntimeProcessor::process_bm_set_default_action;
    processMap_["bm_table_delete_entry"] = &RuntimeProcessor::process_bm_table_delete_entry;
    processMap_["bm_learning_ack"] = &RuntimeProcessor::process_bm_learning_ack;
    processMap_["bm_learning_ack_buffer"] = &RuntimeProcessor::process_bm_learning_ack_buffer;
  }

  virtual ~RuntimeProcessor() {}
};

class RuntimeProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RuntimeProcessorFactory(const ::boost::shared_ptr< RuntimeIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RuntimeIfFactory > handlerFactory_;
};

class RuntimeMultiface : virtual public RuntimeIf {
 public:
  RuntimeMultiface(std::vector<boost::shared_ptr<RuntimeIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RuntimeMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RuntimeIf> > ifaces_;
  RuntimeMultiface() {}
  void add(boost::shared_ptr<RuntimeIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  BmEntryHandle bm_table_add_exact_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmActionData& action_data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_table_add_exact_match_entry(table_name, action_name, match_key, action_data);
    }
    return ifaces_[i]->bm_table_add_exact_match_entry(table_name, action_name, match_key, action_data);
  }

  BmEntryHandle bm_table_add_lpm_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const int32_t prefix_length, const BmActionData& action_data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_table_add_lpm_entry(table_name, action_name, match_key, prefix_length, action_data);
    }
    return ifaces_[i]->bm_table_add_lpm_entry(table_name, action_name, match_key, prefix_length, action_data);
  }

  BmEntryHandle bm_table_add_ternary_match_entry(const std::string& table_name, const std::string& action_name, const BmMatchKey& match_key, const BmMatchKey& match_mask, const int32_t priority, const BmActionData& action_data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_table_add_ternary_match_entry(table_name, action_name, match_key, match_mask, priority, action_data);
    }
    return ifaces_[i]->bm_table_add_ternary_match_entry(table_name, action_name, match_key, match_mask, priority, action_data);
  }

  void bm_set_default_action(const std::string& table_name, const std::string& action_name, const BmActionData& action_data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_set_default_action(table_name, action_name, action_data);
    }
    ifaces_[i]->bm_set_default_action(table_name, action_name, action_data);
  }

  void bm_table_delete_entry(const std::string& table_name, const BmEntryHandle entry_handle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_table_delete_entry(table_name, entry_handle);
    }
    ifaces_[i]->bm_table_delete_entry(table_name, entry_handle);
  }

  void bm_learning_ack(const BmLearningListId list_id, const BmLearningBufferId buffer_id, const std::vector<BmLearningSampleId> & sample_ids) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_learning_ack(list_id, buffer_id, sample_ids);
    }
    ifaces_[i]->bm_learning_ack(list_id, buffer_id, sample_ids);
  }

  void bm_learning_ack_buffer(const BmLearningListId list_id, const BmLearningBufferId buffer_id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->bm_learning_ack_buffer(list_id, buffer_id);
    }
    ifaces_[i]->bm_learning_ack_buffer(list_id, buffer_id);
  }

};

} // namespace

#endif
