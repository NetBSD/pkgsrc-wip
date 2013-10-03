$NetBSD: patch-tinycustom.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- tinycustom.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ tinycustom.el	2013-10-03 19:33:10.000000000 +0900
@@ -50,7 +50,7 @@ DOC is the variable documentation.
 
 This is a defcustom only for emulating purpose.
 Its effect is just as same as that of defvar."
-  (` (defvar (, symbol) (, value) (, doc))))
+  `(defvar ,symbol ,value ,doc))
 
 (defvar-maybe frame-background-mode nil
   "*The brightness of the background.
