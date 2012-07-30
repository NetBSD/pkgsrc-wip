$NetBSD: patch-lisp_tc.el,v 1.1 2012/07/30 13:50:31 makoto Exp $

s/last-command-char/last-command-event/

--- lisp/tc.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/tc.el	2012-07-30 22:27:44.000000000 +0900
@@ -682,7 +682,7 @@
 (defun tcode-input-method (ch)
   "The input method function for T-Code."
   (setq last-command 'self-insert-command
-	last-command-char ch)
+	last-command-event ch)
   (if input-method-verbose-flag
       (unless tcode-input-method-verbose-flag
 	;; push some variables' values
@@ -1233,7 +1233,7 @@
   "Encode Tcode character and insert."
   (interactive "P")
   (tcode-cancel-undo-boundary)
-  (let ((events (tcode-input-method last-command-char)))
+  (let ((events (tcode-input-method last-command-event)))
     (while events
       (let* ((ch (car events))
 	     (command (tcode-default-key-binding (char-to-string ch))))
@@ -1244,7 +1244,7 @@
 	      (setq command 'self-insert-command))
 	  (setq prefix-arg current-prefix-arg
 		this-command command
-		last-command-char ch) ; for self-insert-command
+		last-command-event ch) ; for self-insert-command
 	  (command-execute command)))
       (setq events (cdr events)))))
 
