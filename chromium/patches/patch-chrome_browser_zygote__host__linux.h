$NetBSD: patch-chrome_browser_zygote__host__linux.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/zygote_host_linux.h.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/zygote_host_linux.h
@@ -51,6 +51,9 @@ class ZygoteHost {
     kCmdReap = 1,                  // Reap a renderer child.
     kCmdGetTerminationStatus = 2,  // Check what happend to a child process.
     kCmdGetSandboxStatus = 3,      // Read a bitmask of kSandbox*
+#if defined(OS_BSD)
+    kCmdEnd = 5,              // Kill zygote for SOCK_DGRAM.
+#endif
   };
 
   // These form a bitmask which describes the conditions of the sandbox that
