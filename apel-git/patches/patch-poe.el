$NetBSD: patch-poe.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- poe.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ poe.el	2013-10-03 19:33:10.000000000 +0900
@@ -1667,7 +1667,7 @@ See `walk-windows' for the meaning of MI
                      )))
       ;; arglist: (prefix &optional dir-flag suffix)
       (cond
-       ((not arglist)
+       ((or (not arglist) (not (listp arglist)))
         ;; `make-temp-file' is a built-in; expects 3-args.
         (put 'make-temp-file 'defun-maybe '3-args))
        ((> (length arglist) 3)
