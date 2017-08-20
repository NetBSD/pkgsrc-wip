$NetBSD$

--- test/tsan/tls_race2.cc.orig	2017-07-04 05:53:07.000000000 +0000
+++ test/tsan/tls_race2.cc
@@ -28,3 +28,4 @@ int main() {
 // CHECK-Linux:   Location is TLS of thread T1.
 // CHECK-FreeBSD:   Location is TLS of thread T1.
 // CHECK-Darwin:   Location is heap block of size 4
+// CHECK-NetBSD:   Location is TLS of thread T1.
