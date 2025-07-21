$NetBSD$

For size_t.

--- src/common/rwfile.h.orig	2025-07-21 19:38:54.440889238 +0000
+++ src/common/rwfile.h
@@ -1,6 +1,7 @@
 #ifndef RWFILE_H
 #define RWFILE_H
 
+#include <cstddef>
 #include <vector>
 
 bool readfile(char const *path, std::vector<char> *out, int maxsize);
