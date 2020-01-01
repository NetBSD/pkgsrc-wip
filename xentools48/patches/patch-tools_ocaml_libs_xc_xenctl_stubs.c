$NetBSD$

char buffer too small

--- tools/ocaml/libs/xc/xenctrl_stubs.c.orig	2018-12-03 18:03:57.000000000 +0900
+++ tools/ocaml/libs/xc/xenctrl_stubs.c	2020-01-01 20:11:19.784021537 +0900
@@ -54,7 +54,7 @@
 
 static void Noreturn failwith_xc(xc_interface *xch)
 {
-	char error_str[256];
+	char error_str[1192];
 	if (xch) {
 		const xc_error *error = xc_get_last_error(xch);
 		if (error->code == XC_ERROR_NONE)
