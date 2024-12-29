$NetBSD$

compat has been gone away (now built-in)

--- lisp/with-editor.el.orig	2024-12-01 23:19:07.000000000 +0900
+++ lisp/with-editor.el	2024-12-29 21:21:50.844380634 +0900
@@ -78,7 +78,7 @@
 ;;; Code:
 
 (require 'cl-lib)
-(require 'compat)
+;;(require 'compat)
 (require 'server)
 (require 'shell)
 (eval-when-compile (require 'subr-x))
