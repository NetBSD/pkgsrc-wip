$NetBSD: patch-lisp_eelll.el,v 1.1 2012/07/30 13:50:31 makoto Exp $

s/last-command-char/last-command-event/

--- lisp/eelll.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/eelll.el	2012-07-30 22:29:25.000000000 +0900
@@ -1000,7 +1000,7 @@
   (interactive)
   (save-excursion
     (set-buffer " *eelll: strokes*")
-    (insert (char-to-string last-command-char)))
+    (insert (char-to-string last-command-event)))
   (if eelll-move-cursor
       (insert " ")))
 
