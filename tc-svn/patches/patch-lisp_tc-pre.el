$NetBSD: patch-lisp_tc-pre.el,v 1.1 2012/08/06 14:58:41 makoto Exp $

One line left as old version, fix.

--- lisp/tc-pre.el.orig	2012-08-06 23:22:57.000000000 +0900
+++ lisp/tc-pre.el	2012-08-06 23:21:29.000000000 +0900
@@ -95,7 +95,7 @@
 
 ;;;; Version
 
-(defconst tcode-version "2.3.1")
+(defconst tcode-version "3.0")
 
 (defun tcode-version ()
   "Tコード入力環境のバージョンを表示する。"
