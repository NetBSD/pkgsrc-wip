$NetBSD: patch-src_api.cpp,v 1.3 2014/06/11 19:03:53 thomasklausner Exp $

Fix path to jsoncpp headers.

--- src/api.cpp.orig	2014-06-11 17:49:36.000000000 +0000
+++ src/api.cpp
@@ -9,7 +9,7 @@
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
-#include <jsoncpp/json/json.h>
+#include <json/json.h>
 
 size_t writeMemoryCallback(char *ptr, size_t size, size_t nmemb, void *userp) {
     std::ostringstream *stream = (std::ostringstream*)userp;
