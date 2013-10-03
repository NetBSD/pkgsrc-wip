$NetBSD: patch-poe-18.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- poe-18.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ poe-18.el	2013-10-03 19:33:10.000000000 +0900
@@ -492,9 +492,9 @@ With optional non-nil ALL, force redispl
 ;; that works ok in practice (people should not use that variable elsewhere).
 (defmacro save-match-data (&rest body)
   "Execute the BODY forms, restoring the global value of the match data."
-  (` (let ((save-match-data-internal (match-data)))
-       (unwind-protect (progn (,@ body))
-         (set-match-data save-match-data-internal)))))
+  `(let ((save-match-data-internal (match-data)))
+     (unwind-protect (progn ,@ body)
+       (set-match-data save-match-data-internal))))
 
 
 ;;; @ Basic editing commands.
