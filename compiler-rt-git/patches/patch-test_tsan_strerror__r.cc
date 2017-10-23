$NetBSD$

--- test/tsan/strerror_r.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ test/tsan/strerror_r.cc
@@ -11,7 +11,8 @@
 char buffer[1000];
 
 void *Thread(void *p) {
-  return strerror_r(TEST_ERROR, buffer, sizeof(buffer));
+  strerror_r(TEST_ERROR, buffer, sizeof(buffer));
+  return buffer;
 }
 
 int main() {
