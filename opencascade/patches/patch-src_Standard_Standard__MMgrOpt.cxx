$NetBSD$

--- src/Standard/Standard_MMgrOpt.cxx.orig	2016-04-04 14:58:18.000000000 +0000
+++ src/Standard/Standard_MMgrOpt.cxx
@@ -244,7 +244,7 @@ void Standard_MMgrOpt::Initialize()
       perror("ERR_MEMRY_FAIL");
 #endif
     
-#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(__linux__) || defined(linux) || defined(__FreeBSD__) || defined(__ANDROID__)
+#if defined(IRIX) || defined(__sgi) || defined(SOLARIS) || defined(__sun) || defined(__linux__) || defined(linux) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(__NetBSD__)
     if ((myMMap = open ("/dev/zero", O_RDWR)) < 0) {
       if ((myMMap = open ("/dev/null", O_RDWR)) < 0){
         myMMap = 0;
