$NetBSD$

convert obsolete set-face-underline-p to
                 set-face-underline

(be carefull, for 'cat this file', that may confuse terminal session

--- lisp/tc-mazegaki.el.orig	2025-04-09 22:00:43.000000000 +0900
+++ lisp/tc-mazegaki.el	2025-04-09 22:04:29.000000000 +0900
@@ -93,7 +93,7 @@ nil �ξ��ˤ���¸����ʤ���")
       nil
     (prog1
 	(make-face 'mazegaki-conversion)
-      (set-face-underline-p 'mazegaki-conversion t)))
+      (set-face-underline 'mazegaki-conversion t)))
   "* �򤼽��Ѵ����Ѵ��оݤ�ɽ��ʸ������Ѥ���face��
 mule2 �ʾ�ޤ��� XEmacs �ξ��Τ�ͭ����")
 (defvar tcode-mazegaki-prefix-overlay nil)
