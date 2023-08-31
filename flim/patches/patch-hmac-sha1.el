$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./hmac-sha1.el	2005-07-06 11:09:04.000000000 +0900
+++ ././hmac-sha1.el	2020-09-05 16:02:39.899264499 +0900
@@ -1,4 +1,4 @@
-;;; hmac-sha1.el --- Compute HMAC-SHA1.
+;;; hmac-sha1.el --- Compute HMAC-SHA1.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1999, 2001  Free Software Foundation, Inc.
 
@@ -64,19 +64,11 @@
 ;;; Code:
 
 (eval-when-compile (require 'hmac-def))
-(require 'hex-util)			; (decode-hex-string STRING)
 (require 'sha1)				; expects (sha1 STRING)
 
-;; To share *.elc files between Emacs w/ and w/o DL patch,
-;; this check must be done at load-time.
-(cond
- ((fboundp 'sha1-binary)
-  ;; do nothing.
-  )
- (t
-  (defun sha1-binary (string)
-    "Return the SHA1 of STRING in binary form."
-    (decode-hex-string (sha1 string)))))
+(defun sha1-binary (string)
+  "Return the SHA1 of STRING in binary form."
+  (secure-hash 'sha1 string nil nil t))
 
 (define-hmac-function hmac-sha1 sha1-binary 64 20) ; => (hmac-sha1 TEXT KEY)
 (define-hmac-function hmac-sha1-96 sha1-binary 64 20 96)
