$NetBSD: patch-src_downloader.cpp,v 1.2 2014/05/25 12:58:41 thomasklausner Exp $

Fix path to jsoncpp headers.

--- src/downloader.cpp.orig	2014-04-24 10:00:00.000000000 +0000
+++ src/downloader.cpp
@@ -20,7 +20,7 @@
 #include <boost/regex.hpp>
 #include <boost/date_time/posix_time/posix_time_types.hpp>
 #include <tinyxml.h>
-#include <jsoncpp/json/json.h>
+#include <json/json.h>
 #include <htmlcxx/html/ParserDom.h>
 #include <htmlcxx/html/Uri.h>
 
@@ -1389,12 +1389,22 @@ CURLcode Downloader::beginDownload()
 std::string Downloader::getResponse(const std::string& url)
 {
     std::ostringstream memory;
+    usleep(50000); // wait 50ms
 
     curl_easy_setopt(curlhandle, CURLOPT_URL, url.c_str());
     curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 1);
     curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, Downloader::writeMemoryCallback);
     curl_easy_setopt(curlhandle, CURLOPT_WRITEDATA, &memory);
-    CURLcode result = curl_easy_perform(curlhandle);
+
+    CURLcode result;
+    this->retries = 0;
+    do
+    {
+        result = curl_easy_perform(curlhandle);
+    }
+    while ((result != CURLE_OK) && (this->retries++ < config.iRetries));
+    this->retries = 0; // reset retries counter
+
     curl_easy_setopt(curlhandle, CURLOPT_WRITEFUNCTION, Downloader::writeData);
     curl_easy_setopt(curlhandle, CURLOPT_NOPROGRESS, 0);
     std::string response = memory.str();
