$NetBSD$

--- setup.py.orig	2017-05-22 13:43:12.000000000 +0000
+++ setup.py
@@ -19,7 +19,7 @@ try:
     pf = platform.system()
     if pf != 'Windows' and lc == (None, None):
         locale.setlocale(locale.LC_ALL, 'C.UTF-8')
-except (ValueError, UnicodeError):
+except:
     locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
 
 
