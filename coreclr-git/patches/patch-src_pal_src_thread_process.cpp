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
@@ -1398,9 +1403,15 @@ static bool IsCoreClrModule(const char* 
 // to clean up its semaphore. 
 // Note to anyone modifying these names in the future: Semaphore names on OS X are limited
 // to SEM_NAME_LEN characters, including null. SEM_NAME_LEN is 31 (at least on OS X 10.11).
-static const char* RuntimeStartupSemaphoreName = "/clrst%08x%016llx";
-static const char* RuntimeOldContinueSemaphoreName = "/clrco%08x%016llx";
-static const char* RuntimeContinueSemaphoreName = "/clrct%08x%016llx";
+// NetBSD limits semaphore names to 15 characters, including null (at least up to 7.99.25).
+static const char* RuntimeStartupSemaphoreName = "/clrst%08llx";
+static const char* RuntimeOldContinueSemaphoreName = "/clrco%08llx";
+static const char* RuntimeContinueSemaphoreName = "/clrct%08llx";
+
+static uint64_t HashSemaphoreName(uint64_t a, uint64_t b)
+{
+	return (a ^ b) & 0xffffffff;
+}
 
 class PAL_RuntimeStartupHelper
 {
@@ -1437,12 +1448,12 @@ public:
     {
         if (m_startupSem != SEM_FAILED)
         {
-            char startupSemName[NAME_MAX - 4];
+            char startupSemName[CLR_SEM_MAX_NAMELEN];
             sprintf_s(startupSemName,
                       sizeof(startupSemName),
                       RuntimeStartupSemaphoreName,
-                      m_processId,
-                      m_processIdDisambiguationKey);
+                      HashSemaphoreName(m_processId,
+                                        m_processIdDisambiguationKey));
 
             sem_close(m_startupSem);
             sem_unlink(startupSemName);
@@ -1501,7 +1512,7 @@ public:
     PAL_ERROR Register()
     {
         CPalThread *pThread = InternalGetCurrentThread();
-        char startupSemName[NAME_MAX - 4];
+        char startupSemName[CLR_SEM_MAX_NAMELEN];
         PAL_ERROR pe = NO_ERROR;
 
         // See semaphore name format for details about this value. We store it so that
@@ -1513,8 +1524,8 @@ public:
         sprintf_s(startupSemName,
                   sizeof(startupSemName),
                   RuntimeStartupSemaphoreName,
-                  m_processId,
-                  m_processIdDisambiguationKey);
+                  HashSemaphoreName(m_processId,
+                                    m_processIdDisambiguationKey));
 
         TRACE("PAL_RuntimeStartupHelper.Register startup sem '%s'\n", startupSemName);
 
@@ -1618,15 +1629,15 @@ public:
 
     void StartupHelperThread()
     {
-        char continueSemName[NAME_MAX - 4];
+        char continueSemName[CLR_SEM_MAX_NAMELEN];
         sem_t *continueSem = SEM_FAILED;
         PAL_ERROR pe = NO_ERROR;
 
         sprintf_s(continueSemName,
                   sizeof(continueSemName),
                   RuntimeContinueSemaphoreName,
-                  m_processId,
-                  m_processIdDisambiguationKey);
+                  HashSemaphoreName(m_processId,
+                                    m_processIdDisambiguationKey));
 
         TRACE("StartupHelperThread continue sem '%s'\n", continueSemName);
 
@@ -1793,15 +1804,15 @@ BOOL
 PALAPI
 PAL_NotifyRuntimeStarted()
 {
-    char startupSemName[NAME_MAX - 4];
+    char startupSemName[CLR_SEM_MAX_NAMELEN];
     sem_t *startupSem = SEM_FAILED;
     BOOL result = TRUE;
 
     UINT64 processIdDisambiguationKey = 0;
     GetProcessIdDisambiguationKey(gPID, &processIdDisambiguationKey);
 
-    sprintf_s(startupSemName, sizeof(startupSemName), RuntimeStartupSemaphoreName, gPID, processIdDisambiguationKey);
-    sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeOldContinueSemaphoreName, gPID, processIdDisambiguationKey);
+    sprintf_s(startupSemName, sizeof(startupSemName), RuntimeStartupSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
+    sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeOldContinueSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
 
     TRACE("PAL_NotifyRuntimeStarted opening continue (old) '%s' startup '%s'\n", g_continueSemName, startupSemName);
 
@@ -1810,7 +1821,7 @@ PAL_NotifyRuntimeStarted()
     if (g_continueSem == SEM_FAILED)
     {
         // Create the new continue semaphore name "clrctXXXX"
-        sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeContinueSemaphoreName, gPID, processIdDisambiguationKey);
+        sprintf_s(g_continueSemName, sizeof(g_continueSemName), RuntimeContinueSemaphoreName, HashSemaphoreName(gPID, processIdDisambiguationKey));
 
         TRACE("PAL_NotifyRuntimeStarted creating continue '%s'\n", g_continueSemName);
 
