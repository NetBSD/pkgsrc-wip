$NetBSD: patch-lisp_tc-sysdep.el,v 1.1 2013/01/22 13:54:22 makoto Exp $
(1)
 To work with emacs-25 or later
 You will get following error if C-s tried for incremental search.
 Symbol's function definition is void: isearch-last-command-char

--- lisp/tc-sysdep.el.orig	2018-07-27 22:40:27.540117546 +0900
+++ lisp/tc-sysdep.el	2018-07-27 22:44:27.936253867 +0900
@@ -228,7 +228,7 @@ BODY should be a list of lisp expression
 ;;;
 ;;; Fix incompatibilities between 18 and 19.
 ;;;
-(if (string-match "^\\(19\\|2[0123]\\)" emacs-version)
+(if (string-match "^\\(19\\|2[0-9]\\)" emacs-version)
     (progn
       (defun tcode-redo-command (ch)
 	"キー CH を現在のキーマップで再実行する"
