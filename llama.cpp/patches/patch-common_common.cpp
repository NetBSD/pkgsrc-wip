$NetBSD$

--- common/common.cpp.orig	2026-05-29 05:46:11.000000000 +0000
+++ common/common.cpp
@@ -436,10 +436,10 @@ std::string string_format(const char * f
 std::string string_strip(const std::string & str) {
     size_t start = 0;
     size_t end = str.size();
-    while (start < end && std::isspace(str[start])) {
+    while (start < end && std::isspace((unsigned char)(str[start]))) {
         start++;
     }
-    while (end > start && std::isspace(str[end - 1])) {
+    while (end > start && std::isspace((unsigned char)(str[end - 1]))) {
         end--;
     }
     return str.substr(start, end - start);
