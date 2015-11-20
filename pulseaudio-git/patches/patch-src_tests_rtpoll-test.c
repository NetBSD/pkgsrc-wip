$NetBSD: patch-src_tests_rtpoll-test.c,v 1.1 2014/06/09 13:08:19 ryoon Exp $

Build fix for systems without real-time signals.

--- src/tests/rtpoll-test.c.orig	2015-09-10 04:51:41.000000000 +0000
+++ src/tests/rtpoll-test.c
@@ -83,6 +83,7 @@ START_TEST (rtpoll_test) {
 END_TEST
 
 int main(int argc, char *argv[]) {
+#ifdef SIGRTMIN
     int failed = 0;
     Suite *s;
     TCase *tc;
@@ -103,4 +104,7 @@ int main(int argc, char *argv[]) {
     srunner_free(sr);
 
     return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
+#else
+    return 0
+#endif
 }
