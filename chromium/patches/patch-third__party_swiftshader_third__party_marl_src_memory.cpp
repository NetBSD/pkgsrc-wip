$NetBSD$

--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2020-07-15 19:01:48.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,7 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
