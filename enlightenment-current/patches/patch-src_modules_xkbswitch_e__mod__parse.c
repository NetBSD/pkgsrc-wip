$NetBSD$

* teach location from pkgsrc

--- src/modules/xkbswitch/e_mod_parse.c.orig	2020-05-17 19:40:56.451332600 +0000
+++ src/modules/xkbswitch/e_mod_parse.c
@@ -67,6 +67,9 @@ find_rules(void)
         XKB_BASE "/rules/xorg.lst",
         XKB_BASE "/rules/xfree86.lst",
 #endif
+#if defined PKGSRC_X11BASE
+      PKGSRC_X11BASE "/share/X11/xkb/rules/base.lst",
+#endif
 #if defined __NetBSD__
         "/usr/X11R7/lib/X11/xkb/rules/xorg.lst",
 #elif defined __OpenBSD__
