$NetBSD$

--- src/3rdparty/chromium/extensions/common/stack_frame.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/extensions/common/stack_frame.cc
@@ -7,7 +7,7 @@
 #include <string>
 
 #include "base/strings/utf_string_conversions.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace extensions {
 
