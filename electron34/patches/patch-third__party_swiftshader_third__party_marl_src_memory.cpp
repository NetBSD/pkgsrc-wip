$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,8 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__OpenBSD__) || \
+      defined(__NetBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
