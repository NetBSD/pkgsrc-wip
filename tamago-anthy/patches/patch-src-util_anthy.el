$NetBSD: patch-src-util_anthy.el,v 1.1 2013/02/12 06:45:09 makoto Exp $

last-command-char -> last-command-event

--- src-util/anthy.el.orig	2008-11-29 21:46:00.000000000 +0900
+++ ../anthy-9100h/src-util/anthy.el	2013-02-12 15:35:58.000000000 +0900
@@ -892,7 +892,7 @@
 	 ((event-matches-key-specifier-p event 'backspace) 8)
 	 (t
 	  (char-to-int (event-to-character event)))))
-    last-command-char))
+    last-command-event))
 
 ;;
 ;;
