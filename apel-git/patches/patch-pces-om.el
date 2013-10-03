$NetBSD: patch-pces-om.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- pces-om.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ pces-om.el	2013-10-03 19:33:10.000000000 +0900
@@ -227,24 +227,24 @@ applied to `coding-system-for-write'."
 (make-coding-system 'binary nil ?= "No conversion")
 
 (defmacro as-binary-process (&rest body)
-  (` (let (selective-display	; Disable ^M to nl translation.
-	   ;; Mule
-	   mc-flag
-	   (default-process-coding-system (cons *noconv* *noconv*))
-	   program-coding-system-alist)
-       (,@ body))))
+  `(let (selective-display	; Disable ^M to nl translation.
+	 ;; Mule
+	 mc-flag
+	 (default-process-coding-system (cons *noconv* *noconv*))
+	 program-coding-system-alist)
+     ,@ body))
 
 (defmacro as-binary-input-file (&rest body)
-  (` (let (mc-flag
-	   (file-coding-system-for-read *noconv*)
-	   )
-       (,@ body))))
+  `(let (mc-flag
+	 (file-coding-system-for-read *noconv*)
+	 )
+     ,@ body))
 
 (defmacro as-binary-output-file (&rest body)
-  (` (let (mc-flag
-	   (file-coding-system *noconv*)
-	   )
-       (,@ body))))
+  `(let (mc-flag
+	 (file-coding-system *noconv*)
+	 )
+     ,@ body))
 
 (defalias 'set-process-input-coding-system 'set-process-coding-system)
 
