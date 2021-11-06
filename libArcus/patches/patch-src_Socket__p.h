$NetBSD$

Fix build against protobuf 3.18+

--- src/Socket_p.h.orig	2021-11-06 03:27:34.010477969 +0000
+++ src/Socket_p.h
@@ -548,7 +548,7 @@ namespace Arcus
 
         google::protobuf::io::ArrayInputStream array(wire_message->data, wire_message->size);
         google::protobuf::io::CodedInputStream stream(&array);
-        stream.SetTotalBytesLimit(message_size_maximum, message_size_warning);
+        stream.SetTotalBytesLimit(message_size_maximum);
         if(!message->ParseFromCodedStream(&stream))
         {
             error(ErrorCode::ParseFailedError, "Failed to parse message:" + std::string(wire_message->data));
