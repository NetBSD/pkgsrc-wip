$NetBSD$

convert obsolete set-face-underline-p to
                 set-face-underline

(be carefull, for 'cat this file', that may confuse terminal session

--- lisp/tc-mazegaki.el.orig	2025-04-09 22:00:43.000000000 +0900
+++ lisp/tc-mazegaki.el	2025-04-09 22:04:29.000000000 +0900
@@ -93,7 +93,7 @@ nil の場合には保存されない。")
       nil
     (prog1
 	(make-face 'mazegaki-conversion)
-      (set-face-underline-p 'mazegaki-conversion t)))
+      (set-face-underline 'mazegaki-conversion t)))
   "* 交ぜ書き変換の変換対象を表す文字列に用いるface。
 mule2 以上または XEmacs の場合のみ有効。")
 (defvar tcode-mazegaki-prefix-overlay nil)
