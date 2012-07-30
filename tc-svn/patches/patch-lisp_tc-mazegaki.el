$NetBSD: patch-lisp_tc-mazegaki.el,v 1.1 2012/07/30 13:50:31 makoto Exp $

s/last-command-char/last-command-event/

--- lisp/tc-mazegaki.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/tc-mazegaki.el	2012-07-30 22:29:18.000000000 +0900
@@ -1583,7 +1583,7 @@
 		     (setq comp (append (cdr list) comp))
 		     (rplacd list nil)))
 		  ((or (= ch ?\t)
-		       (= ch last-command-char))
+		       (= ch last-command-event))
 		   ;; 先頭の候補を選択して終了
 		   (insert (substring (car comp)
 				      (length yomi-prefix) nil))
