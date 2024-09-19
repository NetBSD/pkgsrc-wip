$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/time.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/stdc/time.d
@@ -86,6 +86,10 @@ else version( DragonFlyBSD )
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
@@ -153,6 +157,13 @@ else version( DragonFlyBSD )
 {
     ///
     void tzset();                            // non-standard
+    ///
+    extern __gshared const(char)*[2] tzname; // non-standard
+}
+else version( NetBSD )
+{
+    ///
+    void tzset();                            // non-standard
     ///
     extern __gshared const(char)*[2] tzname; // non-standard
 }
