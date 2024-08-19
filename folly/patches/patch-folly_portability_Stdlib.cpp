$NetBSD$

NetBSD support.

--- folly/portability/Stdlib.cpp.orig	2024-08-19 19:49:07.896669823 +0000
+++ folly/portability/Stdlib.cpp
@@ -147,6 +147,10 @@ int unsetenv(const char* name) {
 #include <string>
 #include <vector>
 
+extern "C" {
+extern char **environ;
+}
+
 extern "C" int clearenv() {
   std::vector<std::string> data;
   for (auto it = environ; it && *it; ++it) {
