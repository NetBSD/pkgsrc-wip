$NetBSD$

--- Templates/Empty/web/source/npplugin/windows/nptypes.h.orig	2016-07-12 13:56:01.000000000 +0000
+++ Templates/Empty/web/source/npplugin/windows/nptypes.h
@@ -58,7 +58,7 @@
   #ifndef __cplusplus
     typedef int bool;
   #endif
-#elif defined(bsdi) || defined(FREEBSD) || defined(OPENBSD)
+#elif defined(bsdi) || defined(FREEBSD) || defined(OPENBSD) || defined(__NetBSD__)
   /*
    * BSD/OS, FreeBSD, and OpenBSD ship sys/types.h that define int32_t and 
    * u_int32_t.
