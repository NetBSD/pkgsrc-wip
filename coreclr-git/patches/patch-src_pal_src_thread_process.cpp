$NetBSD$

--- src/pal/src/thread/process.cpp.orig	2016-04-22 07:58:05.000000000 +0000
+++ src/pal/src/thread/process.cpp
@@ -1398,9 +1398,10 @@ static bool IsCoreClrModule(const char* 
 // to clean up its semaphore. 
 // Note to anyone modifying these names in the future: Semaphore names on OS X are limited
 // to SEM_NAME_LEN characters, including null. SEM_NAME_LEN is 31 (at least on OS X 10.11).
-static const char* RuntimeStartupSemaphoreName = "/clrst%08x%016llx";
-static const char* RuntimeOldContinueSemaphoreName = "/clrco%08x%016llx";
-static const char* RuntimeContinueSemaphoreName = "/clrct%08x%016llx";
+// NetBSD limits semaphore names to 15 characters, including null (at least up to 7.99.25).
+static const char* RuntimeStartupSemaphoreName = "/clrst%04x%04llx";
+static const char* RuntimeOldContinueSemaphoreName = "/clrco%08x%04llx";
+static const char* RuntimeContinueSemaphoreName = "/clrct%04x%04llx";
 
 class PAL_RuntimeStartupHelper
 {
