$NetBSD$

Allow build on BSD-like OSes to continue.

--- vfe/unix/syspovconfig.h.orig	2021-07-08 09:56:01.000000000 +0000
+++ vfe/unix/syspovconfig.h
@@ -162,7 +162,7 @@ const int NULL=0;
     #include <sys/param.h>
     #if defined(BSD)
         // BSD-style Unix detected.
-        #error BSD-style Unix detected, but not explicitly supported yet; proceed at your own risk.
+        // #error BSD-style Unix detected, but not explicitly supported yet; proceed at your own risk.
     #else
         // Not officially supported yet; comment-out the following line to try with default POSIX settings.
         #error Unix detected, but flavor not identified; proceed at your own risk.
