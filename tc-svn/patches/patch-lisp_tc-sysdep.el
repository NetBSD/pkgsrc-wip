$NetBSD: patch-lisp_tc-sysdep.el,v 1.3 2012/07/30 13:50:31 makoto Exp $

To work with emacs-22 or later
You will get following error if C-s tried for incremental search.
Symbol's function definition is void: isearch-last-command-char

--- lisp/tc-sysdep.el.orig	2012-07-30 22:24:44.000000000 +0900
+++ lisp/tc-sysdep.el	2012-07-30 22:29:16.000000000 +0900
@@ -228,7 +228,7 @@
 ;;;
 ;;; Fix incompatibilities between 18 and 19.
 ;;;
-(if (string-match "^\\(19\\|2[0123]\\)" emacs-version)
+(if (string-match "^\\(19\\|2[0-9]\\)" emacs-version)
     (progn
       (defun tcode-redo-command (ch)
 	"キー CH を現在のキーマップで再実行する"
@@ -240,7 +240,7 @@
       ;; XEmacs
       (or (fboundp 'isearch-last-command-char)
 	  (defun isearch-last-command-char ()
-	    last-command-char))
+	    last-command-event))
       (or (boundp 'search-upper-case)
 	  (setq search-upper-case 'not-yanks)))
   ;; NEmacs
