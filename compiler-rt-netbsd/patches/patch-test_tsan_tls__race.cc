$NetBSD$

--- test/tsan/tls_race.cc.orig	2017-06-03 23:53:55.000000000 +0000
+++ test/tsan/tls_race.cc
@@ -20,4 +20,5 @@ int main() {
 // CHECK: WARNING: ThreadSanitizer: data race
 // CHECK-Linux:   Location is TLS of main thread.
 // CHECK-FreeBSD:   Location is TLS of main thread.
+// CHECK-NetBSD:   Location is TLS of main thread.
 // CHECK-Darwin:   Location is heap block of size 4
