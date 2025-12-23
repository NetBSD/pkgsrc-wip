$NetBSD$

--- src/pipewiresourceitem.cpp.orig	2025-11-04 14:59:25.000000000 +0000
+++ src/pipewiresourceitem.cpp
@@ -29,7 +29,11 @@
 
 static void pwInit()
 {
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     pw_init(nullptr, nullptr);
+#else
+    pipewire_init(nullptr, nullptr);
+#endif
 }
 Q_COREAPP_STARTUP_FUNCTION(pwInit);
 
