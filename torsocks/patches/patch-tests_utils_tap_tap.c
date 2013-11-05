$NetBSD: patch-tests_utils_tap_tap.c,v 1.1 2013/11/05 14:56:43 thomasklausner Exp $

isdigit() only accepts unsigned chars and -1.
NetBSD's version is quite picky about this.

--- tests/utils/tap/tap.c.orig	2013-11-03 18:24:51.000000000 +0000
+++ tests/utils/tap/tap.c
@@ -94,7 +94,7 @@ _gen_result(int ok, const char *func, ch
 		if(local_test_name) {
 			name_is_digits = 1;
 			for(c = local_test_name; *c != '\0'; c++) {
-				if(!isdigit(*c) && !isspace(*c)) {
+				if(!isdigit((unsigned char)*c) && !isspace((unsigned char)*c)) {
 					name_is_digits = 0;
 					break;
 				}
