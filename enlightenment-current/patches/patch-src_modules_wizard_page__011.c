$NetBSD$

* teach location from pkgsrc

--- src/modules/wizard/page_011.c.orig	2020-07-26 16:39:12.133980300 +0000
+++ src/modules/wizard/page_011.c
@@ -23,6 +23,9 @@ find_rules(void)
       XKB_BASE "/rules/xorg.lst",
       XKB_BASE "/rules/xfree86.lst",
 #endif
+#if defined PKGSRC_X11BASE
+      PKGSRC_X11BASE "/share/X11/xkb/rules/base.lst",
+#endif
 #if defined __NetBSD__
       "/usr/X11R7/lib/X11/xkb/rules/xorg.lst",
 #elif defined __OpenBSD__
