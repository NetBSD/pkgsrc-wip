$NetBSD$

--- libraries/source/nvtt/src/src/nvcore/poshlib/posh.h.orig	2015-07-21 15:53:21.000000000 +0000
+++ libraries/source/nvtt/src/src/nvcore/poshlib/posh.h
@@ -298,6 +298,11 @@ Metrowerks:
 #  define POSH_OS_STRING "FreeBSD"
 #endif
 
+#if defined __NetBSD__
+#  define POSH_OS_NETBSD 1 
+#  define POSH_OS_STRING "NetBSD"
+#endif
+
 #if defined __OpenBSD__
 #  define POSH_OS_OPENBSD 1
 #  define POSH_OS_STRING "OpenBSD"
@@ -1018,5 +1023,3 @@ extern posh_i64_t  POSH_ReadI64FromBig( 
 #ifdef __cplusplus
 }
 #endif
-
-
