$NetBSD: patch-poem-ltn1.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- poem-ltn1.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ poem-ltn1.el	2013-10-03 19:33:10.000000000 +0900
@@ -110,7 +110,7 @@ but the contents viewed as characters do
 
 (defmacro char-next-index (char index)
   "Return index of character succeeding CHAR whose index is INDEX."
-  (` (1+ (, index))))
+  `(1+ ,index))
 
 
 ;;; @ string
