$NetBSD$

* Import patch from chromium

--- src/Reactor/Debug.cpp.orig	2025-11-19 17:24:16.492389802 +0000
+++ src/Reactor/Debug.cpp
@@ -46,7 +46,8 @@ namespace {
 
 bool IsUnderDebugger()
 {
-#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)
+#if defined(PTRACE) && !defined(__APPLE__) && !defined(__MACH__)&& !defined(__OpenBSD__) && !defined(__FreeBSD__) && \
+    !defined(__NetBSD__)
 	static bool checked = false;
 	static bool res = false;
 
