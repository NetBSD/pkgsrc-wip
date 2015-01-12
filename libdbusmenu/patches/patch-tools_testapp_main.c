$NetBSD: patch-tools_testapp_main.c,v 1.1 2015/01/12 02:23:56 obache Exp $

* prevent to using deprecated API

--- tools/testapp/main.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ tools/testapp/main.c
@@ -135,7 +135,9 @@ name_lost (GDBusConnection * connection,
 
 int main (int argc, char ** argv)
 {
+#if !GLIB_CHECK_VERSION(2,36,0)
 	g_type_init();
+#endif
 
 	if (argc != 2) {
 		g_warning(USAGE);
