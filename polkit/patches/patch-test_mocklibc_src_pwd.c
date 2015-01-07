$NetBSD: patch-test_mocklibc_src_pwd.c,v 1.1 2015/01/07 05:38:31 obache Exp $

* XXX: no fgetpwent(3)

--- test/mocklibc/src/pwd.c.orig	2013-02-02 03:22:52.000000000 +0000
+++ test/mocklibc/src/pwd.c
@@ -27,6 +27,12 @@
 
 static FILE *global_stream = NULL;
 
+#ifdef __NetBSD__
+static struct passwd *fgetpwent(FILE* stream) {
+  return NULL;
+}
+#endif
+
 void setpwent(void) {
   if (global_stream)
     endpwent();
