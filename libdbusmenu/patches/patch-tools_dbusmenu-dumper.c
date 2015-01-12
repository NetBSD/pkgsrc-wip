$NetBSD: patch-tools_dbusmenu-dumper.c,v 1.1 2015/01/12 02:23:56 obache Exp $

* prevent to using deprecated API

--- tools/dbusmenu-dumper.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ tools/dbusmenu-dumper.c
@@ -388,7 +388,9 @@ static GOptionEntry general_options[] = 
 int
 main (int argc, char ** argv)
 {
+#if !GLIB_CHECK_VERSION(2,36,0)
 	g_type_init();
+#endif
 	GError * error = NULL;
 	GOptionContext * context;
 
