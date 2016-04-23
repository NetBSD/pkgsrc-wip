$NetBSD$

--- src/pal/src/thread/process.cpp.orig	2016-04-22 07:58:05.000000000 +0000
+++ src/pal/src/thread/process.cpp
@@ -130,9 +130,14 @@ Volatile<LONG> terminator = 0;
 // Process ID of this process.
 DWORD gPID = (DWORD) -1;
 
+// The lowest common supported semaphore length, including null character
+// NetBSD-7.99.25: 15 characters
+// MacOSX 10.11: 31
+#define CLR_SEM_MAX_NAMELEN 15
+
 // The runtime waits on this semaphore if the dbgshim startup semaphore exists
 Volatile<sem_t *> g_continueSem = SEM_FAILED;
-char g_continueSemName[NAME_MAX - 4];
+char g_continueSemName[CLR_SEM_MAX_NAMELEN];
 
 // Function to call during PAL/process shutdown/abort
 Volatile<PSHUTDOWN_CALLBACK> g_shutdownCallback = nullptr;
@@ -1398,9 +1403,10 @@ static bool IsCoreClrModule(const char* 
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
@@ -1437,7 +1443,7 @@ public:
     {
         if (m_startupSem != SEM_FAILED)
         {
-            char startupSemName[NAME_MAX - 4];
+            char startupSemName[CLR_SEM_MAX_NAMELEN];
             sprintf_s(startupSemName,
                       sizeof(startupSemName),
                       RuntimeStartupSemaphoreName,
@@ -1501,7 +1507,7 @@ public:
     PAL_ERROR Register()
     {
         CPalThread *pThread = InternalGetCurrentThread();
-        char startupSemName[NAME_MAX - 4];
+        char startupSemName[CLR_SEM_MAX_NAMELEN];
         PAL_ERROR pe = NO_ERROR;
 
         // See semaphore name format for details about this value. We store it so that
@@ -1618,7 +1624,7 @@ public:
 
     void StartupHelperThread()
     {
-        char continueSemName[NAME_MAX - 4];
+        char continueSemName[CLR_SEM_MAX_NAMELEN];
         sem_t *continueSem = SEM_FAILED;
         PAL_ERROR pe = NO_ERROR;
 
@@ -1793,7 +1799,7 @@ BOOL
 PALAPI
 PAL_NotifyRuntimeStarted()
 {
-    char startupSemName[NAME_MAX - 4];
+    char startupSemName[CLR_SEM_MAX_NAMELEN];
     sem_t *startupSem = SEM_FAILED;
     BOOL result = TRUE;
 
