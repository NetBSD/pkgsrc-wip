$NetBSD: patch-lisp_tc-ja-alnum.el,v 1.1 2012/07/30 13:50:31 makoto Exp $

s/last-command-char/last-command-event/

--- lisp/tc-ja-alnum.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/tc-ja-alnum.el	2012-07-30 22:29:20.000000000 +0900
@@ -79,14 +79,14 @@
 (defun tcode-2byte-alnum-input-method (ch)
   "The 2byte alnum input function for T-Code."
   (setq last-command 'self-insert-command
-	last-command-char ch)
+	last-command-event ch)
   (list (tcode-1-to-2 ch)))
 
 (unless (boundp 'input-method-function)
   (defun tcode-2byte-alnum-self-insert-command (&optional arg)
     "Translate character and insert."
     (interactive "P")
-    (let ((ch (car (tcode-2byte-alnum-input-method last-command-char))))
+    (let ((ch (car (tcode-2byte-alnum-input-method last-command-event))))
       (insert (char-to-string ch))))
 
   ;; マイナーモード
