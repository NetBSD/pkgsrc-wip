$NetBSD$

--- src/llama-chat.cpp.orig	2025-05-16 09:52:08.885488932 +0000
+++ src/llama-chat.cpp
@@ -16,10 +16,10 @@
 static std::string trim(const std::string & str) {
     size_t start = 0;
     size_t end = str.size();
-    while (start < end && isspace(str[start])) {
+    while (start < end && isspace((unsigned char)(str[start]))) {
         start += 1;
     }
-    while (end > start && isspace(str[end - 1])) {
+    while (end > start && isspace((unsigned char)(str[end - 1]))) {
         end -= 1;
     }
     return str.substr(start, end - start);
