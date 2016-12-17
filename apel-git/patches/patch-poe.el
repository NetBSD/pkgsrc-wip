$NetBSD: patch-poe.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

(1)
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
(2)
Fix following problem for emacs-26 (25.1.50)
Loading `poe': old-style backquotes detected!
Invalid read syntax: "Expected opening brace after \\N"
gmake: *** [Makefile:31: elc] Error 255

--- poe.el.orig	2016-03-12 23:30:31.000000000 +0900
+++ poe.el	2016-12-14 19:08:13.000000000 +0900
@@ -1081,7 +1081,7 @@ then capitalize each word in NEWTEXT.
 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
   `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\N' means substitute what matched the Nth `\(...\)'.
        If Nth parens didn't match, substitute nothing.
   `\\' means insert one `\'.
 FIXEDCASE and LITERAL are optional arguments.
@@ -1133,7 +1133,7 @@ then capitalize each word in NEWTEXT.
 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
   `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\N' means substitute what matched the Nth `\(...\)'.
        If Nth parens didn't match, substitute nothing.
   `\\' means insert one `\'.
 FIXEDCASE and LITERAL are optional arguments.
@@ -1667,7 +1667,7 @@ See `walk-windows' for the meaning of MI
                      )))
       ;; arglist: (prefix &optional dir-flag suffix)
       (cond
-       ((not arglist)
+       ((or (not arglist) (not (listp arglist)))
         ;; `make-temp-file' is a built-in; expects 3-args.
         (put 'make-temp-file 'defun-maybe '3-args))
        ((> (length arglist) 3)
