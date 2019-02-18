$NetBSD$

--- src/libs/xpcom18a4/nsprpub/pr/include/md/_netbsd.h.orig	2018-12-18 13:01:23.000000000 +0000
+++ src/libs/xpcom18a4/nsprpub/pr/include/md/_netbsd.h
@@ -57,6 +57,8 @@
 #elif defined(__arm32__) || defined(__arm__) || defined(__armel__) \
     || defined(__armeb__)
 #define _PR_SI_ARCHITECTURE "arm"
+#elif defined(__amd64__)
+#define _PR_SI_ARCHITECTURE "amd64"
 #endif
 
 #if defined(__ELF__)
