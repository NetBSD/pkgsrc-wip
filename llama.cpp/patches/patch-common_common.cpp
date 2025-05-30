$NetBSD$

--- common/common.cpp.orig	2025-05-30 10:24:37.000000000 +0000
+++ common/common.cpp
@@ -401,10 +401,10 @@ std::string string_format(const char * f
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
@@ -849,7 +849,7 @@ std::string fs_get_cache_directory() {
     if (getenv("LLAMA_CACHE")) {
         cache_directory = std::getenv("LLAMA_CACHE");
     } else {
-#if defined(__linux__) || defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(_AIX) || defined(__OpenBSD__) || defined(__NetBSD__)
         if (std::getenv("XDG_CACHE_HOME")) {
             cache_directory = std::getenv("XDG_CACHE_HOME");
         } else {
