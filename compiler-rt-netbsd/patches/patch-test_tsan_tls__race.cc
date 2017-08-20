$NetBSD$

--- test/tsan/tls_race.cc.orig	2017-07-04 05:53:07.000000000 +0000
+++ test/tsan/tls_race.cc
@@ -21,3 +21,4 @@ int main() {
 // CHECK-Linux:   Location is TLS of main thread.
 // CHECK-FreeBSD:   Location is TLS of main thread.
 // CHECK-Darwin:   Location is heap block of size 4
+// CHECK-NetBSD:   Location is TLS of main thread.
