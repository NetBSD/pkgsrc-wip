$NetBSD$

--- Source/WebKit/Platform/IPC/ArgumentCoders.h.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/Platform/IPC/ArgumentCoders.h
@@ -38,6 +38,10 @@
 #include <wtf/Variant.h>
 #include <wtf/WallTime.h>
 
+#ifdef __APPLE__
+#include <mach/mach.h>        /* audit_token_t */
+#endif
+
 namespace IPC {
 
 // An argument coder works on POD types
