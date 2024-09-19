$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/time.d.orig	2020-05-07 08:52:17.274678259 +0000
+++ runtime/druntime/src/core/sys/posix/time.d
@@ -60,6 +60,10 @@ else version( NetBSD )
 {
     time_t timegm(tm*); // non-standard
 }
+else version( NetBSD )
+{
+    time_t timegm(tm*); // non-standard
+}
 else version (Solaris)
 {
     time_t timegm(tm*); // non-standard
