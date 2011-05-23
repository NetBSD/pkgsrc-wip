$NetBSD: patch-lisp_tc-sysdep.el,v 1.1.1.1 2011/05/23 13:37:52 makoto Exp $

To work with emacs-22 or later

--- lisp/tc-sysdep.el.orig	2011-04-14 05:04:48.000000000 +0000
+++ lisp/tc-sysdep.el
@@ -228,7 +228,7 @@ BODY should be a list of lisp expression
 ;;;
 ;;; Fix incompatibilities between 18 and 19.
 ;;;
-(if (string-match "^\\(19\\|2[01]\\)" emacs-version)
+(if (string-match "^\\(19\\|2[0-9]\\)" emacs-version)
     (progn
       (defun tcode-redo-command (ch)
 	"キー CH を現在のキーマップで再実行する"
