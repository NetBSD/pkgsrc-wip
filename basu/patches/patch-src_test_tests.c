$NetBSD$

--- src/test/tests.c.orig	2022-12-16 10:13:02.000000000 +0000
+++ src/test/tests.c
@@ -1,12 +1,13 @@
 /* SPDX-License-Identifier: LGPL-2.1+ */
 
 #include <stdlib.h>
+#include <string.h>
 #include <util.h>
 
 #include "env-util.h"
 #include "tests.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define program_invocation_short_name getprogname()
 #endif
 
@@ -22,7 +23,7 @@ int log_tests_skipped(const char *messag
 }
 
 int log_tests_skipped_errno(int r, const char *message) {
-        log_notice_errno(r, "%s: %s, skipping tests: %m",
-                         program_invocation_short_name, message);
+        log_notice_errno(r, LOG_ERR_FMT("%s: %s, skipping tests", r,
+                         program_invocation_short_name, message));
         return EXIT_TEST_SKIP;
 }
