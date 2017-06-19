$NetBSD$

--- test/tsan/tls_race2.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/tsan/tls_race2.cc
@@ -27,4 +27,5 @@ int main() {
 // CHECK: WARNING: ThreadSanitizer: data race
 // CHECK-Linux:   Location is TLS of thread T1.
 // CHECK-FreeBSD:   Location is TLS of thread T1.
+// CHECK-NetBSD:   Location is TLS of thread T1.
 // CHECK-Darwin:   Location is heap block of size 4
