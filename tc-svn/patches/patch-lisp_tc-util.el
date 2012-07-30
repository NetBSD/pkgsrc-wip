$NetBSD: patch-lisp_tc-util.el,v 1.1 2012/07/30 13:50:31 makoto Exp $

s/last-command-char/last-command-event/

--- lisp/tc-util.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/tc-util.el	2012-07-30 22:29:13.000000000 +0900
@@ -305,7 +305,7 @@
 					      (tcode-preceding-char))))
 			      (string-match (regexp-quote prev-char)
 					    tcode-no-following-space-chars)))
-		       (tcode-redo-command last-command-char)))
+		       (tcode-redo-command last-command-event)))
 	       (condition-case nil
 		   (let* ((echo-keystrokes 0)
 			  (ch (read-char)))
@@ -398,7 +398,7 @@
 	  (cond (elm
 		 (let (current-prefix-arg)
 		   (tcode-insert elm)))
-		((= ch last-command-char)
+		((= ch last-command-event)
 		 (tcode-insert-ya-outset (1+ level)))
 		((= ch ? )
 		 (self-insert-command level))
@@ -633,7 +633,7 @@
     (unwind-protect
 	(let* ((echo-keystrokes 0)
 	       (ch (read-char)))
-	  (cond ((= ch last-command-char)
+	  (cond ((= ch last-command-event)
 		 (tcode-katakana-preceding-chars (1+ arg)))
 		((= ch ?\C-?)
 		 (tcode-katakana-preceding-chars (- arg)))
