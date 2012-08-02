$NetBSD: patch-lisp_tc.el,v 1.2 2012/08/02 14:38:50 makoto Exp $

(1) convert last-command-char       to last-command-event
 s/last-command-char/last-command-event/
(2) convert inactivate-input-method to deactivate-input-method
(3) define following name-of-the-function and function itself 
  (setq deactivate-current-input-method-function 
       'tc-deactivate-current-input-method-function)

--- lisp/tc.el.orig	2012-08-02 16:43:08.000000000 +0900
+++ lisp/tc.el	2012-08-02 23:34:08.000000000 +0900
@@ -682,7 +682,7 @@
 (defun tcode-input-method (ch)
   "The input method function for T-Code."
   (setq last-command 'self-insert-command
-	last-command-char ch)
+	last-command-event ch)
   (if input-method-verbose-flag
       (unless tcode-input-method-verbose-flag
 	;; push some variables' values
@@ -1077,16 +1077,8 @@
   (if tcode-use-isearch
       (require tcode-isearch-type))
   (add-hook 'minibuffer-exit-hook 'tcode-exit-minibuffer)
-  (when (and (fboundp 'inactivate-input-method)
+  (when (and (fboundp 'deactivate-input-method)
 	     (fboundp 'defadvice))
-    (defadvice inactivate-input-method (after
-					turn-off-current-input-method-title
-					activate)
-      "Turn off `current-input-method-title' for mode line."
-      (and (string= (car input-method-history)
-		    tcode-current-package)
-	   (setq current-input-method-title
-		 tcode-transparent-mode-indicator)))
     (defadvice activate-input-method (after
 				      turn-on-current-input-method-title
 				      activate)
@@ -1095,6 +1087,16 @@
 		    tcode-current-package)
 	   (tcode-mode-line-redisplay))))
   (provide 'tcode-ready)
+;; see required hook function, see mule-cmds.el (around 1463rd line)
+  (setq deactivate-current-input-method-function 
+	'tc-deactivate-current-input-method-function)
+  (defun tc-deactivate-current-input-method-function ( )
+     "Turn off `current-input-method-title' for mode line."
+     (and (string= (car input-method-history)
+		    tcode-current-package)
+	   (setq current-input-method-title
+		 tcode-transparent-mode-indicator)))
+;; -------------
   (run-hooks 'tcode-ready-hook)
   (tcode-verbose-message
    (tcode-substitute-command-keys
@@ -1200,7 +1202,7 @@
 	(setq libraries (cdr libraries)))
       (tcode-load-table table-name))
     (setq tcode-current-package package-name))
-  (setq inactivate-current-input-method-function 'tcode-inactivate
+  (setq deactivate-current-input-method-function 'tcode-inactivate
 	describe-current-input-method-function 'tcode-mode-help)
   (setq current-input-method-title 'tcode-mode-indicator)
   (tcode-activate))
@@ -1233,7 +1235,7 @@
   "Encode Tcode character and insert."
   (interactive "P")
   (tcode-cancel-undo-boundary)
-  (let ((events (tcode-input-method last-command-char)))
+  (let ((events (tcode-input-method last-command-event)))
     (while events
       (let* ((ch (car events))
 	     (command (tcode-default-key-binding (char-to-string ch))))
@@ -1244,7 +1246,7 @@
 	      (setq command 'self-insert-command))
 	  (setq prefix-arg current-prefix-arg
 		this-command command
-		last-command-char ch) ; for self-insert-command
+		last-command-event ch) ; for self-insert-command
 	  (command-execute command)))
       (setq events (cdr events)))))
 
