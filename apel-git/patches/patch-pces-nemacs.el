$NetBSD: patch-pces-nemacs.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- pces-nemacs.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ pces-nemacs.el	2013-10-03 19:33:10.000000000 +0900
@@ -100,20 +100,20 @@
 ;;;
 
 (defmacro as-binary-process (&rest body)
-  (` (let (selective-display	; Disable ^M to nl translation.
-	   ;; Nemacs
-	   kanji-flag
-	   (default-kanji-process-code 0)
-	   program-kanji-code-alist)
-       (,@ body))))
+  `(let (selective-display	; Disable ^M to nl translation.
+	 ;; Nemacs
+	 kanji-flag
+	 (default-kanji-process-code 0)
+	 program-kanji-code-alist)
+     ,@ body))
 
 (defmacro as-binary-input-file (&rest body)
-  (` (let (kanji-flag default-kanji-flag)
-       (,@ body))))
+  `(let (kanji-flag default-kanji-flag)
+     ,@ body))
 
 (defmacro as-binary-output-file (&rest body)
-  (` (let (kanji-flag)
-       (,@ body))))
+  `(let (kanji-flag)
+     ,@ body))
 
 (defun write-region-as-binary (start end filename
 				     &optional append visit lockname)
