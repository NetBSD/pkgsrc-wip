$NetBSD: patch-extended_ipinfo_support__display.c,v 1.1 2013/06/20 07:25:59 yvs4sf Exp $

extended ipinfo support (display.c part)
https://bugs.launchpad.net/mtr/+bug/701514

diff -ruN display.c.orig display.c
--- display.c.orig	2013-05-15 12:11:37.000000000 +0300
+++ display.c	2013-05-15 12:27:09.000000000 +0300
@@ -98,7 +98,7 @@
   case DisplayCurses:
     mtr_curses_open();  
 #ifndef NO_IPINFO
-    if (ipinfo_no >= 0)
+    if (ipinfo_nos[0] >= 0)
         asn_open();
 #endif
     break;
@@ -129,7 +129,7 @@
     break;
   case DisplayCurses:
 #ifndef NO_IPINFO
-    if (ipinfo_no >= 0)
+    if (ipinfo_nos[0] >= 0)
         asn_close();
 #endif
     mtr_curses_close();
