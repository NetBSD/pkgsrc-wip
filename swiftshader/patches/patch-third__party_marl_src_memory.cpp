$NetBSD$

* Import patch from chromium

--- third_party/marl/src/memory.cpp.orig	2025-11-19 17:33:29.579484646 +0000
+++ third_party/marl/src/memory.cpp
@@ -19,7 +19,8 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
