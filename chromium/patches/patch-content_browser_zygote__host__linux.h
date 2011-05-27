$NetBSD: patch-content_browser_zygote__host__linux.h,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/zygote_host_linux.h.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/zygote_host_linux.h
@@ -51,6 +51,9 @@ class ZygoteHost {
     kCmdReap = 1,                  // Reap a renderer child.
     kCmdGetTerminationStatus = 2,  // Check what happend to a child process.
     kCmdGetSandboxStatus = 3,      // Read a bitmask of kSandbox*
+#if defined(OS_BSD)
+    kCmdEnd = 5,              // Kill zygote for SOCK_DGRAM.
+#endif
   };
 
   // These form a bitmask which describes the conditions of the sandbox that
