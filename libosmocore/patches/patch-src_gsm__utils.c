$NetBSD: patch-src_gsm__utils.c,v 1.1 2011/08/02 22:19:13 khorben Exp $

--- src/gsm_utils.c.orig	2010-11-18 22:53:43.000000000 +0000
+++ src/gsm_utils.c
@@ -355,6 +355,11 @@ void generate_backtrace()
 
 	free(strings);
 }
+#else
+void generate_backtrace()
+{
+# warning generate_backtrace() is not implemented
+}
 #endif
 
 enum gsm_band gsm_arfcn2band(uint16_t arfcn)
