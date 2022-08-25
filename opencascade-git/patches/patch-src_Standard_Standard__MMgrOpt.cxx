$NetBSD$

Add NetBSD support.

--- src/Standard/Standard_MMgrOpt.cxx.orig	2021-10-30 11:13:58.000000000 +0000
+++ src/Standard/Standard_MMgrOpt.cxx
@@ -249,7 +249,7 @@ void Standard_MMgrOpt::Initialize()
       perror("ERR_MEMRY_FAIL");
 #endif
     
-#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(__linux__) || defined(__FreeBSD__) || defined(__ANDROID__)
+#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__ANDROID__)
     if ((myMMap = open ("/dev/zero", O_RDWR)) < 0) {
       if ((myMMap = open ("/dev/null", O_RDWR)) < 0){
         myMMap = 0;
