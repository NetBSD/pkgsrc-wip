$NetBSD: patch-lisp_eelll.el,v 1.1 2013/12/15 14:21:09 makoto Exp $

Replace obsolete variable

--- lisp/eelll.el.orig	2013-12-15 14:31:48.000000000 +0900
+++ lisp/eelll.el	2013-12-15 15:06:25.000000000 +0900
@@ -361,7 +361,7 @@ 
 	  (setq j (1+ j) k 0)
 	  (while (< k 5)
 	    (setq k (1+ k))
-	    (insert "【【【【【  ")
+	    (insert "办办办办办  ")
 	    (if (= k c) (insert "  ")))
 	  (delete-horizontal-space)
 	  (insert "\n"))
@@ -1000,7 +1000,7 @@
   (interactive)
   (save-excursion
     (set-buffer " *eelll: strokes*")
-    (insert (char-to-string last-command-char)))
+    (insert (char-to-string last-command-event)))
   (if eelll-move-cursor
       (insert " ")))
 
