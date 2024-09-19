$NetBSD$

--- src/recompiler/fpu/softfloat-native.h.orig	2016-08-05 16:11:17.000000000 +0000
+++ src/recompiler/fpu/softfloat-native.h
@@ -12,6 +12,7 @@
 
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/param.h>
+#undef PVM
 #endif
 
 /*
