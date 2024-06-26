// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: js_event.proto

#ifndef PROTOBUF_INCLUDED_js_5fevent_2eproto
#define PROTOBUF_INCLUDED_js_5fevent_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_js_5fevent_2eproto 

namespace protobuf_js_5fevent_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_js_5fevent_2eproto
namespace controller {
class Axes;
class AxesDefaultTypeInternal;
extern AxesDefaultTypeInternal _Axes_default_instance_;
class Buttons;
class ButtonsDefaultTypeInternal;
extern ButtonsDefaultTypeInternal _Buttons_default_instance_;
class Xbox;
class XboxDefaultTypeInternal;
extern XboxDefaultTypeInternal _Xbox_default_instance_;
class jsEvent;
class jsEventDefaultTypeInternal;
extern jsEventDefaultTypeInternal _jsEvent_default_instance_;
}  // namespace controller
namespace google {
namespace protobuf {
template<> ::controller::Axes* Arena::CreateMaybeMessage<::controller::Axes>(Arena*);
template<> ::controller::Buttons* Arena::CreateMaybeMessage<::controller::Buttons>(Arena*);
template<> ::controller::Xbox* Arena::CreateMaybeMessage<::controller::Xbox>(Arena*);
template<> ::controller::jsEvent* Arena::CreateMaybeMessage<::controller::jsEvent>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace controller {

// ===================================================================

class jsEvent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:controller.jsEvent) */ {
 public:
  jsEvent();
  virtual ~jsEvent();

  jsEvent(const jsEvent& from);

  inline jsEvent& operator=(const jsEvent& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  jsEvent(jsEvent&& from) noexcept
    : jsEvent() {
    *this = ::std::move(from);
  }

  inline jsEvent& operator=(jsEvent&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const jsEvent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const jsEvent* internal_default_instance() {
    return reinterpret_cast<const jsEvent*>(
               &_jsEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(jsEvent* other);
  friend void swap(jsEvent& a, jsEvent& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline jsEvent* New() const final {
    return CreateMaybeMessage<jsEvent>(NULL);
  }

  jsEvent* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<jsEvent>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const jsEvent& from);
  void MergeFrom(const jsEvent& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(jsEvent* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 time = 1;
  bool has_time() const;
  void clear_time();
  static const int kTimeFieldNumber = 1;
  ::google::protobuf::uint32 time() const;
  void set_time(::google::protobuf::uint32 value);

  // required int32 value = 2;
  bool has_value() const;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // required uint32 type = 3;
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 3;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // required uint32 number = 4;
  bool has_number() const;
  void clear_number();
  static const int kNumberFieldNumber = 4;
  ::google::protobuf::uint32 number() const;
  void set_number(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:controller.jsEvent)
 private:
  void set_has_time();
  void clear_has_time();
  void set_has_value();
  void clear_has_value();
  void set_has_type();
  void clear_has_type();
  void set_has_number();
  void clear_has_number();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 time_;
  ::google::protobuf::int32 value_;
  ::google::protobuf::uint32 type_;
  ::google::protobuf::uint32 number_;
  friend struct ::protobuf_js_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Xbox : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:controller.Xbox) */ {
 public:
  Xbox();
  virtual ~Xbox();

  Xbox(const Xbox& from);

  inline Xbox& operator=(const Xbox& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Xbox(Xbox&& from) noexcept
    : Xbox() {
    *this = ::std::move(from);
  }

  inline Xbox& operator=(Xbox&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Xbox& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Xbox* internal_default_instance() {
    return reinterpret_cast<const Xbox*>(
               &_Xbox_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Xbox* other);
  friend void swap(Xbox& a, Xbox& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Xbox* New() const final {
    return CreateMaybeMessage<Xbox>(NULL);
  }

  Xbox* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Xbox>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Xbox& from);
  void MergeFrom(const Xbox& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Xbox* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .controller.Axes axes = 1;
  bool has_axes() const;
  void clear_axes();
  static const int kAxesFieldNumber = 1;
  private:
  const ::controller::Axes& _internal_axes() const;
  public:
  const ::controller::Axes& axes() const;
  ::controller::Axes* release_axes();
  ::controller::Axes* mutable_axes();
  void set_allocated_axes(::controller::Axes* axes);

  // optional .controller.Buttons buttons = 2;
  bool has_buttons() const;
  void clear_buttons();
  static const int kButtonsFieldNumber = 2;
  private:
  const ::controller::Buttons& _internal_buttons() const;
  public:
  const ::controller::Buttons& buttons() const;
  ::controller::Buttons* release_buttons();
  ::controller::Buttons* mutable_buttons();
  void set_allocated_buttons(::controller::Buttons* buttons);

  // @@protoc_insertion_point(class_scope:controller.Xbox)
 private:
  void set_has_axes();
  void clear_has_axes();
  void set_has_buttons();
  void clear_has_buttons();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::controller::Axes* axes_;
  ::controller::Buttons* buttons_;
  friend struct ::protobuf_js_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Axes : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:controller.Axes) */ {
 public:
  Axes();
  virtual ~Axes();

  Axes(const Axes& from);

  inline Axes& operator=(const Axes& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Axes(Axes&& from) noexcept
    : Axes() {
    *this = ::std::move(from);
  }

  inline Axes& operator=(Axes&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Axes& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Axes* internal_default_instance() {
    return reinterpret_cast<const Axes*>(
               &_Axes_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Axes* other);
  friend void swap(Axes& a, Axes& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Axes* New() const final {
    return CreateMaybeMessage<Axes>(NULL);
  }

  Axes* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Axes>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Axes& from);
  void MergeFrom(const Axes& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Axes* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 l_x = 1 [default = 0];
  bool has_l_x() const;
  void clear_l_x();
  static const int kLXFieldNumber = 1;
  ::google::protobuf::int32 l_x() const;
  void set_l_x(::google::protobuf::int32 value);

  // optional sint32 l_y = 2 [default = 0];
  bool has_l_y() const;
  void clear_l_y();
  static const int kLYFieldNumber = 2;
  ::google::protobuf::int32 l_y() const;
  void set_l_y(::google::protobuf::int32 value);

  // optional sint32 r_x = 3 [default = 0];
  bool has_r_x() const;
  void clear_r_x();
  static const int kRXFieldNumber = 3;
  ::google::protobuf::int32 r_x() const;
  void set_r_x(::google::protobuf::int32 value);

  // optional sint32 r_y = 4 [default = 0];
  bool has_r_y() const;
  void clear_r_y();
  static const int kRYFieldNumber = 4;
  ::google::protobuf::int32 r_y() const;
  void set_r_y(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:controller.Axes)
 private:
  void set_has_l_x();
  void clear_has_l_x();
  void set_has_l_y();
  void clear_has_l_y();
  void set_has_r_x();
  void clear_has_r_x();
  void set_has_r_y();
  void clear_has_r_y();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int32 l_x_;
  ::google::protobuf::int32 l_y_;
  ::google::protobuf::int32 r_x_;
  ::google::protobuf::int32 r_y_;
  friend struct ::protobuf_js_5fevent_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Buttons : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:controller.Buttons) */ {
 public:
  Buttons();
  virtual ~Buttons();

  Buttons(const Buttons& from);

  inline Buttons& operator=(const Buttons& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Buttons(Buttons&& from) noexcept
    : Buttons() {
    *this = ::std::move(from);
  }

  inline Buttons& operator=(Buttons&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Buttons& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Buttons* internal_default_instance() {
    return reinterpret_cast<const Buttons*>(
               &_Buttons_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(Buttons* other);
  friend void swap(Buttons& a, Buttons& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Buttons* New() const final {
    return CreateMaybeMessage<Buttons>(NULL);
  }

  Buttons* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Buttons>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Buttons& from);
  void MergeFrom(const Buttons& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Buttons* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bool x = 1 [default = false];
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  bool x() const;
  void set_x(bool value);

  // optional bool y = 2 [default = false];
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  bool y() const;
  void set_y(bool value);

  // optional bool b = 3 [default = false];
  bool has_b() const;
  void clear_b();
  static const int kBFieldNumber = 3;
  bool b() const;
  void set_b(bool value);

  // optional bool a = 4 [default = false];
  bool has_a() const;
  void clear_a();
  static const int kAFieldNumber = 4;
  bool a() const;
  void set_a(bool value);

  // optional bool start = 5 [default = false];
  bool has_start() const;
  void clear_start();
  static const int kStartFieldNumber = 5;
  bool start() const;
  void set_start(bool value);

  // optional bool rb = 6 [default = false];
  bool has_rb() const;
  void clear_rb();
  static const int kRbFieldNumber = 6;
  bool rb() const;
  void set_rb(bool value);

  // optional bool lb = 7 [default = false];
  bool has_lb() const;
  void clear_lb();
  static const int kLbFieldNumber = 7;
  bool lb() const;
  void set_lb(bool value);

  // @@protoc_insertion_point(class_scope:controller.Buttons)
 private:
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();
  void set_has_b();
  void clear_has_b();
  void set_has_a();
  void clear_has_a();
  void set_has_start();
  void clear_has_start();
  void set_has_rb();
  void clear_has_rb();
  void set_has_lb();
  void clear_has_lb();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  bool x_;
  bool y_;
  bool b_;
  bool a_;
  bool start_;
  bool rb_;
  bool lb_;
  friend struct ::protobuf_js_5fevent_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// jsEvent

// required uint32 time = 1;
inline bool jsEvent::has_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void jsEvent::set_has_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void jsEvent::clear_has_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void jsEvent::clear_time() {
  time_ = 0u;
  clear_has_time();
}
inline ::google::protobuf::uint32 jsEvent::time() const {
  // @@protoc_insertion_point(field_get:controller.jsEvent.time)
  return time_;
}
inline void jsEvent::set_time(::google::protobuf::uint32 value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:controller.jsEvent.time)
}

// required int32 value = 2;
inline bool jsEvent::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void jsEvent::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void jsEvent::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void jsEvent::clear_value() {
  value_ = 0;
  clear_has_value();
}
inline ::google::protobuf::int32 jsEvent::value() const {
  // @@protoc_insertion_point(field_get:controller.jsEvent.value)
  return value_;
}
inline void jsEvent::set_value(::google::protobuf::int32 value) {
  set_has_value();
  value_ = value;
  // @@protoc_insertion_point(field_set:controller.jsEvent.value)
}

// required uint32 type = 3;
inline bool jsEvent::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void jsEvent::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void jsEvent::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void jsEvent::clear_type() {
  type_ = 0u;
  clear_has_type();
}
inline ::google::protobuf::uint32 jsEvent::type() const {
  // @@protoc_insertion_point(field_get:controller.jsEvent.type)
  return type_;
}
inline void jsEvent::set_type(::google::protobuf::uint32 value) {
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:controller.jsEvent.type)
}

// required uint32 number = 4;
inline bool jsEvent::has_number() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void jsEvent::set_has_number() {
  _has_bits_[0] |= 0x00000008u;
}
inline void jsEvent::clear_has_number() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void jsEvent::clear_number() {
  number_ = 0u;
  clear_has_number();
}
inline ::google::protobuf::uint32 jsEvent::number() const {
  // @@protoc_insertion_point(field_get:controller.jsEvent.number)
  return number_;
}
inline void jsEvent::set_number(::google::protobuf::uint32 value) {
  set_has_number();
  number_ = value;
  // @@protoc_insertion_point(field_set:controller.jsEvent.number)
}

// -------------------------------------------------------------------

// Xbox

// optional .controller.Axes axes = 1;
inline bool Xbox::has_axes() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Xbox::set_has_axes() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Xbox::clear_has_axes() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Xbox::clear_axes() {
  if (axes_ != NULL) axes_->Clear();
  clear_has_axes();
}
inline const ::controller::Axes& Xbox::_internal_axes() const {
  return *axes_;
}
inline const ::controller::Axes& Xbox::axes() const {
  const ::controller::Axes* p = axes_;
  // @@protoc_insertion_point(field_get:controller.Xbox.axes)
  return p != NULL ? *p : *reinterpret_cast<const ::controller::Axes*>(
      &::controller::_Axes_default_instance_);
}
inline ::controller::Axes* Xbox::release_axes() {
  // @@protoc_insertion_point(field_release:controller.Xbox.axes)
  clear_has_axes();
  ::controller::Axes* temp = axes_;
  axes_ = NULL;
  return temp;
}
inline ::controller::Axes* Xbox::mutable_axes() {
  set_has_axes();
  if (axes_ == NULL) {
    auto* p = CreateMaybeMessage<::controller::Axes>(GetArenaNoVirtual());
    axes_ = p;
  }
  // @@protoc_insertion_point(field_mutable:controller.Xbox.axes)
  return axes_;
}
inline void Xbox::set_allocated_axes(::controller::Axes* axes) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete axes_;
  }
  if (axes) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      axes = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, axes, submessage_arena);
    }
    set_has_axes();
  } else {
    clear_has_axes();
  }
  axes_ = axes;
  // @@protoc_insertion_point(field_set_allocated:controller.Xbox.axes)
}

// optional .controller.Buttons buttons = 2;
inline bool Xbox::has_buttons() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Xbox::set_has_buttons() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Xbox::clear_has_buttons() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Xbox::clear_buttons() {
  if (buttons_ != NULL) buttons_->Clear();
  clear_has_buttons();
}
inline const ::controller::Buttons& Xbox::_internal_buttons() const {
  return *buttons_;
}
inline const ::controller::Buttons& Xbox::buttons() const {
  const ::controller::Buttons* p = buttons_;
  // @@protoc_insertion_point(field_get:controller.Xbox.buttons)
  return p != NULL ? *p : *reinterpret_cast<const ::controller::Buttons*>(
      &::controller::_Buttons_default_instance_);
}
inline ::controller::Buttons* Xbox::release_buttons() {
  // @@protoc_insertion_point(field_release:controller.Xbox.buttons)
  clear_has_buttons();
  ::controller::Buttons* temp = buttons_;
  buttons_ = NULL;
  return temp;
}
inline ::controller::Buttons* Xbox::mutable_buttons() {
  set_has_buttons();
  if (buttons_ == NULL) {
    auto* p = CreateMaybeMessage<::controller::Buttons>(GetArenaNoVirtual());
    buttons_ = p;
  }
  // @@protoc_insertion_point(field_mutable:controller.Xbox.buttons)
  return buttons_;
}
inline void Xbox::set_allocated_buttons(::controller::Buttons* buttons) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete buttons_;
  }
  if (buttons) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      buttons = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, buttons, submessage_arena);
    }
    set_has_buttons();
  } else {
    clear_has_buttons();
  }
  buttons_ = buttons;
  // @@protoc_insertion_point(field_set_allocated:controller.Xbox.buttons)
}

// -------------------------------------------------------------------

// Axes

// optional sint32 l_x = 1 [default = 0];
inline bool Axes::has_l_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Axes::set_has_l_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Axes::clear_has_l_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Axes::clear_l_x() {
  l_x_ = 0;
  clear_has_l_x();
}
inline ::google::protobuf::int32 Axes::l_x() const {
  // @@protoc_insertion_point(field_get:controller.Axes.l_x)
  return l_x_;
}
inline void Axes::set_l_x(::google::protobuf::int32 value) {
  set_has_l_x();
  l_x_ = value;
  // @@protoc_insertion_point(field_set:controller.Axes.l_x)
}

// optional sint32 l_y = 2 [default = 0];
inline bool Axes::has_l_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Axes::set_has_l_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Axes::clear_has_l_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Axes::clear_l_y() {
  l_y_ = 0;
  clear_has_l_y();
}
inline ::google::protobuf::int32 Axes::l_y() const {
  // @@protoc_insertion_point(field_get:controller.Axes.l_y)
  return l_y_;
}
inline void Axes::set_l_y(::google::protobuf::int32 value) {
  set_has_l_y();
  l_y_ = value;
  // @@protoc_insertion_point(field_set:controller.Axes.l_y)
}

// optional sint32 r_x = 3 [default = 0];
inline bool Axes::has_r_x() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Axes::set_has_r_x() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Axes::clear_has_r_x() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Axes::clear_r_x() {
  r_x_ = 0;
  clear_has_r_x();
}
inline ::google::protobuf::int32 Axes::r_x() const {
  // @@protoc_insertion_point(field_get:controller.Axes.r_x)
  return r_x_;
}
inline void Axes::set_r_x(::google::protobuf::int32 value) {
  set_has_r_x();
  r_x_ = value;
  // @@protoc_insertion_point(field_set:controller.Axes.r_x)
}

// optional sint32 r_y = 4 [default = 0];
inline bool Axes::has_r_y() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Axes::set_has_r_y() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Axes::clear_has_r_y() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Axes::clear_r_y() {
  r_y_ = 0;
  clear_has_r_y();
}
inline ::google::protobuf::int32 Axes::r_y() const {
  // @@protoc_insertion_point(field_get:controller.Axes.r_y)
  return r_y_;
}
inline void Axes::set_r_y(::google::protobuf::int32 value) {
  set_has_r_y();
  r_y_ = value;
  // @@protoc_insertion_point(field_set:controller.Axes.r_y)
}

// -------------------------------------------------------------------

// Buttons

// optional bool x = 1 [default = false];
inline bool Buttons::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Buttons::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Buttons::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Buttons::clear_x() {
  x_ = false;
  clear_has_x();
}
inline bool Buttons::x() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.x)
  return x_;
}
inline void Buttons::set_x(bool value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.x)
}

// optional bool y = 2 [default = false];
inline bool Buttons::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Buttons::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Buttons::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Buttons::clear_y() {
  y_ = false;
  clear_has_y();
}
inline bool Buttons::y() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.y)
  return y_;
}
inline void Buttons::set_y(bool value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.y)
}

// optional bool b = 3 [default = false];
inline bool Buttons::has_b() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Buttons::set_has_b() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Buttons::clear_has_b() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Buttons::clear_b() {
  b_ = false;
  clear_has_b();
}
inline bool Buttons::b() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.b)
  return b_;
}
inline void Buttons::set_b(bool value) {
  set_has_b();
  b_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.b)
}

// optional bool a = 4 [default = false];
inline bool Buttons::has_a() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Buttons::set_has_a() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Buttons::clear_has_a() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Buttons::clear_a() {
  a_ = false;
  clear_has_a();
}
inline bool Buttons::a() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.a)
  return a_;
}
inline void Buttons::set_a(bool value) {
  set_has_a();
  a_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.a)
}

// optional bool start = 5 [default = false];
inline bool Buttons::has_start() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Buttons::set_has_start() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Buttons::clear_has_start() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Buttons::clear_start() {
  start_ = false;
  clear_has_start();
}
inline bool Buttons::start() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.start)
  return start_;
}
inline void Buttons::set_start(bool value) {
  set_has_start();
  start_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.start)
}

// optional bool rb = 6 [default = false];
inline bool Buttons::has_rb() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Buttons::set_has_rb() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Buttons::clear_has_rb() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Buttons::clear_rb() {
  rb_ = false;
  clear_has_rb();
}
inline bool Buttons::rb() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.rb)
  return rb_;
}
inline void Buttons::set_rb(bool value) {
  set_has_rb();
  rb_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.rb)
}

// optional bool lb = 7 [default = false];
inline bool Buttons::has_lb() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Buttons::set_has_lb() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Buttons::clear_has_lb() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Buttons::clear_lb() {
  lb_ = false;
  clear_has_lb();
}
inline bool Buttons::lb() const {
  // @@protoc_insertion_point(field_get:controller.Buttons.lb)
  return lb_;
}
inline void Buttons::set_lb(bool value) {
  set_has_lb();
  lb_ = value;
  // @@protoc_insertion_point(field_set:controller.Buttons.lb)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace controller

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_js_5fevent_2eproto
