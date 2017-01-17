$NetBSD$

--- src/mapi/table.h.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/mapi/table.h
@@ -40,7 +40,9 @@
 struct mapi_table;
 
 extern const mapi_func table_noop_array[];
-
+#if defined(__NetBSD__) && defined(GLX_USE_TLS)
+extern const mapi_func netbsd_table_noop_array[];
+#endif
 
 typedef void (*nop_handler_proc)(const char *name);
 
