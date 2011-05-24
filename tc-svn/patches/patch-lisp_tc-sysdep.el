$NetBSD: patch-lisp_tc-sysdep.el,v 1.2 2011/05/24 01:46:51 makoto Exp $

To work with emacs-22 or later
You will get following error if C-s tried for incremental search.
Symbol's function definition is void: isearch-last-command-char

--- lisp/tc-sysdep.el.orig	2011-05-24 01:21:00.000000000 +0000
+++ lisp/tc-sysdep.el
@@ -228,7 +228,7 @@ BODY should be a list of lisp expression
 ;;;
 ;;; Fix incompatibilities between 18 and 19.
 ;;;
-(if (string-match "^\\(19\\|2[0123]\\)" emacs-version)
+(if (string-match "^\\(19\\|2[0-9]\\)" emacs-version)
     (progn
       (defun tcode-redo-command (ch)
 	"キー CH を現在のキーマップで再実行する"
