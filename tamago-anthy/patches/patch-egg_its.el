$NetBSD: patch-egg_its.el,v 1.1 2013/02/12 06:45:09 makoto Exp $

last-command-char -> last-command-event

--- its.el.orig	2013-02-12 15:34:03.000000000 +0900
+++ its.el	2013-02-12 15:32:28.000000000 +0900
@@ -397,7 +397,7 @@ This variable override `its-delete-by-ke
 (defun its-self-insert-char ()
   (interactive)
   (let ((inhibit-read-only t)
-	(key last-command-char)
+	(key last-command-event)
 	(cursor (get-text-property (point) 'its-cursor))
 	(syl (get-text-property (1- (point)) 'its-syl)))
     (cond
@@ -1264,7 +1264,7 @@ Return last state."
   (interactive "P")
   (let ((syl (and (null (get-text-property (point) 'its-cursor))
 		  (get-text-property (1- (point)) 'its-syl))))
-    (if (its-keyseq-acceptable-p (vector last-command-char) syl)
+    (if (its-keyseq-acceptable-p (vector last-command-event) syl)
 	(its-self-insert-char)
       (its-kick-convert-region n))))
 
