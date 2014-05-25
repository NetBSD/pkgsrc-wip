$NetBSD: patch-src_api.cpp,v 1.2 2014/05/25 12:58:41 thomasklausner Exp $

Fix path to jsoncpp headers.

--- src/api.cpp.orig	2014-04-24 10:00:00.000000000 +0000
+++ src/api.cpp
@@ -9,7 +9,8 @@
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
-#include <jsoncpp/json/json.h>
+#include <json/json.h>
+#include <unistd.h>
 
 size_t writeMemoryCallback(char *ptr, size_t size, size_t nmemb, void *userp) {
     std::ostringstream *stream = (std::ostringstream*)userp;
@@ -232,6 +233,7 @@ std::string API::getResponse(const std::
         std::cerr << "DEBUG INFO (API::getResponse)" << std::endl << "URL: " << url << std::endl;
     #endif
     std::ostringstream memory;
+    usleep(50000); // wait 50ms
 
     curl_easy_setopt(curlhandle, CURLOPT_URL, url.c_str());
     curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 1);
