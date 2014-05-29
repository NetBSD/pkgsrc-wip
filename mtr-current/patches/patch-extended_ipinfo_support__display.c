--- display.c.orig	2014-05-29 12:31:51.000000000 +0300
+++ display.c	2014-05-14 11:15:03.000000000 +0300
@@ -96,10 +99,6 @@
     break;
   case DisplayCurses:
     mtr_curses_open();  
-#ifdef IPINFO
-    if (ipinfo_no >= 0)
-        asn_open();
-#endif
     break;
   case DisplaySplit:
     split_open();
@@ -127,11 +136,10 @@
     csv_close(now);
     break;
   case DisplayCurses:
+    mtr_curses_close();
 #ifdef IPINFO
-    if (ipinfo_no >= 0)
-        asn_close();
+    asn_close();
 #endif
-    mtr_curses_close();
     break;
   case DisplaySplit:
     split_close();
