$NetBSD$

Migration to protobuf v22.0
* ErrorCollector Migration

Migration to protobuf v30.0
* string_view return type

https://protobuf.dev/support/migration/

--- src/MessageTypeStore.cpp.orig	2021-11-26 15:37:16.000000000 +0000
+++ src/MessageTypeStore.cpp
@@ -52,7 +52,7 @@ class ErrorCollector : public google::pr
 public:
     ErrorCollector() : _error_count(0) { }
 
-    void AddError(const std::string& filename, int line, int column, const std::string& message) override
+    void RecordError(absl::string_view filename, int line, int column, absl::string_view message) override
     {
         _stream << "[" << filename << " (" << line << "," << column << ")] " << message << std::endl;
         _error_count++;
@@ -127,7 +127,7 @@ MessagePtr Arcus::MessageTypeStore::crea
 
 uint32_t Arcus::MessageTypeStore::getMessageTypeId(const MessagePtr& message)
 {
-    return hash(message->GetTypeName());
+    return hash(std::string{message->GetTypeName()});
 }
 
 std::string Arcus::MessageTypeStore::getErrorMessages() const
@@ -137,7 +137,7 @@ std::string Arcus::MessageTypeStore::get
 
 bool Arcus::MessageTypeStore::registerMessageType(const google::protobuf::Message* message_type)
 {
-    uint32_t type_id = hash(message_type->GetTypeName());
+    uint32_t type_id = hash(std::string{message_type->GetTypeName()});
 
     if(hasType(type_id))
     {
@@ -189,7 +189,7 @@ bool Arcus::MessageTypeStore::registerAl
 
         auto message_type = d->message_factory->GetPrototype(message_type_descriptor);
 
-        uint32_t type_id = hash(message_type->GetTypeName());
+        uint32_t type_id = hash(std::string{message_type->GetTypeName()});
 
         d->message_types[type_id] = message_type;
         d->message_type_mapping[message_type_descriptor] = type_id;
