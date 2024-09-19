$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/parallelism.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/parallelism.d
@@ -99,6 +99,11 @@ else version(FreeBSD)
 {
     version = useSysctlbyname;
 }
+else version(NetBSD)
+{
+    version = useSysctlbyname;
+}
+
 
 version(Windows)
 {
@@ -172,6 +177,10 @@ else version(useSysctlbyname)
         {
             auto nameStr = "hw.ncpu\0".ptr;
         }
+        else version(NetBSD)
+        {
+            auto nameStr = "hw.ncpu\0".ptr;
+        }
 
         uint ans;
         size_t len = uint.sizeof;
