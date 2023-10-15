$NetBSD$

NetBSD and some other operating systems do not provide euidaccess.
https://gitlab.gnome.org/World/deja-dup/-/issues/425

--- app/RestoreFileTester.vala.orig	2023-09-22 23:12:56.000000000 +0000
+++ app/RestoreFileTester.vala
@@ -75,12 +75,12 @@ public class RestoreFileTester : Object
         // a file in it. But testing write access is probably good enough for now.
         exists = false;
         string iter = path;
-        int access = -1;
-        while (access != 0 && Posix.errno == Posix.ENOENT) {
+        int ret = -1;
+        while (ret != 0 && Posix.errno == Posix.ENOENT) {
           iter = Path.get_dirname(iter);
-          access = Posix.euidaccess(iter, Posix.W_OK | Posix.X_OK);
+          ret = Posix.access(iter, Posix.W_OK | Posix.X_OK);
         }
-        if (access != 0)
+        if (ret != 0)
           return false;
       }
     } else {
