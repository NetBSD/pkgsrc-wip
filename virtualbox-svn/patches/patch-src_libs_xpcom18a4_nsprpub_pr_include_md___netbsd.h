$NetBSD$

--- src/libs/xpcom18a4/nsprpub/pr/include/md/_netbsd.h.orig	2016-08-05 16:17:21.000000000 +0000
+++ src/libs/xpcom18a4/nsprpub/pr/include/md/_netbsd.h
@@ -57,6 +57,8 @@
 #elif defined(__arm32__) || defined(__arm__) || defined(__armel__) \
     || defined(__armeb__)
 #define _PR_SI_ARCHITECTURE "arm"
+#elif defined(__x86_64__)
+#define _PR_SI_ARCHITECTURE "x86_64"
 #endif
 
 #if defined(__ELF__)
