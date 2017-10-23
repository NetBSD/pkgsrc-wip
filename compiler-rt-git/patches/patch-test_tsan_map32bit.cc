$NetBSD$

--- test/tsan/map32bit.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ test/tsan/map32bit.cc
@@ -12,8 +12,8 @@
 // XFAIL: aarch64
 // XFAIL: powerpc64
 
-// MAP_32BIT doesn't exist on OS X.
-// UNSUPPORTED: darwin
+// MAP_32BIT doesn't exist on OS X and NetBSD.
+// UNSUPPORTED: darwin,netbsd
 
 void *Thread(void *ptr) {
   *(int*)ptr = 42;
@@ -45,4 +45,3 @@ int main() {
 
 // CHECK: WARNING: ThreadSanitizer: data race
 // CHECK: DONE
-
