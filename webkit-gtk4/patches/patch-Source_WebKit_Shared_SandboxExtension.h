$NetBSD$

--- Source/WebKit/Shared/SandboxExtension.h.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/Shared/SandboxExtension.h
@@ -34,6 +34,10 @@
 #include <wtf/Vector.h>
 #include <wtf/text/WTFString.h>
 
+#ifdef __APPLE__
+#include <mach/mach.h>        /* audit_token_t */
+#endif
+
 namespace IPC {
 class Encoder;
 class Decoder;
