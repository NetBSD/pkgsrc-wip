$NetBSD$

Fix build due to upstream changes.

https://github.com/htop-dev/htop/pull/1360

--- netbsd/NetBSDProcess.c.orig	2023-12-29 15:52:13.000000000 +0000
+++ netbsd/NetBSDProcess.c
@@ -237,7 +237,7 @@ static void NetBSDProcess_rowWriteField(
    switch (field) {
    // add NetBSD-specific fields here
    default:
-      Process_writeField(np->super, str, field);
+      Process_writeField(&np->super, str, field);
       return;
    }
 
