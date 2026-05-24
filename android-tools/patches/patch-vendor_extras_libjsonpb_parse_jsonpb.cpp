$NetBSD$

protobuf 27+ changed Descriptor::full_name() to return absl::string_view
instead of const std::string&, which no longer participates in operator+
with std::string. Wrap explicitly so the expression compiles against
both old and new protobuf.

--- vendor/extras/libjsonpb/parse/jsonpb.cpp.orig
+++ vendor/extras/libjsonpb/parse/jsonpb.cpp
@@ -33,7 +33,8 @@ using google::protobuf::util::TypeResolv
 static constexpr char kTypeUrlPrefix[] = "type.googleapis.com";

 std::string GetTypeUrl(const Message& message) {
-  return std::string(kTypeUrlPrefix) + "/" + message.GetDescriptor()->full_name();
+  return std::string(kTypeUrlPrefix) + "/" +
+         std::string(message.GetDescriptor()->full_name());
 }

 ErrorOr<std::string> MessageToJsonString(const Message& message) {
