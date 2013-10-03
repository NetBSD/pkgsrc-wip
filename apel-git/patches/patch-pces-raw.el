$NetBSD: patch-pces-raw.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- pces-raw.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ pces-raw.el	2013-10-03 19:33:10.000000000 +0900
@@ -56,16 +56,16 @@
 ;;;
 
 (defmacro as-binary-process (&rest body)
-  (` (let (selective-display)	; Disable ^M to nl translation.
-       (,@ body))))
+  `(let (selective-display)	; Disable ^M to nl translation.
+     ,@ body))
 
 (defmacro as-binary-input-file (&rest body)
-  (` (let ((emx-binary-mode t)) ; Stop CRLF to LF conversion in OS/2
-       (,@ body))))
+  `(let ((emx-binary-mode t)) ; Stop CRLF to LF conversion in OS/2
+     ,@ body))
 
 (defmacro as-binary-output-file (&rest body)
-  (` (let ((emx-binary-mode t)) ; Stop CRLF to LF conversion in OS/2
-       (,@ body))))
+  `(let ((emx-binary-mode t)) ; Stop CRLF to LF conversion in OS/2
+     ,@ body))
 
 (defun write-region-as-binary (start end filename
 				     &optional append visit lockname)
