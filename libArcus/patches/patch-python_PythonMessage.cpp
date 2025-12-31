$NetBSD$

Migration to protobuf v30.0
* string_view return type

https://protobuf.dev/support/migration/

--- python/PythonMessage.cpp.orig	2025-12-31 14:06:43.017240303 +0000
+++ python/PythonMessage.cpp
@@ -47,7 +47,7 @@ PythonMessage::~PythonMessage()
 
 std::string Arcus::PythonMessage::getTypeName() const
 {
-    return  _message->GetTypeName();
+    return  std::string{_message->GetTypeName()};
 }
 
 MessagePtr Arcus::PythonMessage::getSharedMessage() const
