$NetBSD: patch-3rdparty_protobuf_src_google_protobuf_message__lite.cc,v 1.1 2017/09/04 15:23:49 fhajny Exp $

Needed for INT_MAX.

--- 3rdparty/protobuf/src/google/protobuf/message_lite.cc.orig	2022-12-28 14:31:52.000000000 +0000
+++ 3rdparty/protobuf/src/google/protobuf/message_lite.cc
@@ -38,6 +38,7 @@
 #include <climits>
 #include <cstdint>
 #include <string>
+#include <climits>
 
 #include <google/protobuf/stubs/logging.h>
 #include <google/protobuf/stubs/common.h>
