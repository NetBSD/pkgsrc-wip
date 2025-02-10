$NetBSD$

* Use BSDFileSystemAccess on BSDs

--- sdk/include/megaapi_impl.h.orig	2025-02-06 18:38:02.113595808 +0100
+++ sdk/include/megaapi_impl.h
@@ -90,8 +90,10 @@ class MegaSemaphore : public CppSemaphor
     class MegaWaiter : public PosixWaiter {};
     #ifdef __APPLE__
     class MegaFileSystemAccess : public MacFileSystemAccess {};
-    #else
+    #elif defined(__linux__)
     class MegaFileSystemAccess : public LinuxFileSystemAccess {};
+    #else
+    class MegaFileSystemAccess : public BSDFileSystemAccess {};
     #endif
 #endif
 
