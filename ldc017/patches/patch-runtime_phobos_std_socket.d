$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/socket.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/socket.d
@@ -189,6 +189,14 @@ string formatSocketError(int err) @trust
             else
                 return "Socket error " ~ to!string(err);
         }
+        else version (NetBSD)
+        {
+            auto errs = strerror_r(err, buf.ptr, buf.length);
+            if (errs == 0)
+                cs = buf.ptr;
+            else
+                return "Socket error " ~ to!string(err);
+        }
         else version (Solaris)
         {
             auto errs = strerror_r(err, buf.ptr, buf.length);
