$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/time.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/time.d
@@ -82,6 +82,10 @@ else version( FreeBSD )
 {
     enum clock_t CLOCKS_PER_SEC = 128;
 }
+else version( NetBSD )
+{
+    enum clock_t CLOCKS_PER_SEC = 100;
+}
 else version (CRuntime_Glibc)
 {
     enum clock_t CLOCKS_PER_SEC = 1_000_000;
@@ -145,6 +149,13 @@ else version( FreeBSD )
     ///
     extern __gshared const(char)*[2] tzname; // non-standard
 }
+else version( NetBSD )
+{
+    ///
+    void tzset();                            // non-standard
+    ///
+    extern __gshared const(char)*[2] tzname; // non-standard
+}
 else version (Solaris)
 {
     ///
