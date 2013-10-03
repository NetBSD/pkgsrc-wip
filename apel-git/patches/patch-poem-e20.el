$NetBSD: patch-poem-e20.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

Derived from 
apel (10.8+0.20120427-4), 0.20120427-4.debian.tar.gz 
to fix Following problem:
 ----
 Loading `static': old-style backquotes detected!
 Loading `pym': old-style backquotes detected!
 Loading `product': old-style backquotes detected!
 Eager macro-expansion failure: (wrong-type-argument sequencep 769)
 Loading `poe': old-style backquotes detected!
 Wrong type argument: sequencep, 769
 gmake: *** [elc] Error 255
 ----

--- poem-e20.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ poem-e20.el	2013-10-03 19:33:10.000000000 +0900
@@ -25,6 +25,7 @@
 ;;; Code:
 
 (defun fontset-pixel-size (fontset)
+ (condition-case nil
   (let* ((info (fontset-info fontset))
 	 (height (aref info 1))
 	 )
@@ -32,7 +33,8 @@
 	  ((string-match "-\\([0-9]+\\)-" fontset)
 	   (string-to-number
 	    (substring fontset (match-beginning 1)(match-end 1))))
-	  (t 0))))
+	  (t 0)))
+  (error 0)))
 
 
 ;;; @ character set
