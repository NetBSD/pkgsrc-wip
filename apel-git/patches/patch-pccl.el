$NetBSD: patch-pccl.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- pccl.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ pccl.el	2013-10-03 19:33:10.000000000 +0900
@@ -55,7 +55,7 @@
       "When CCL-PROGRAM is too long, internal buffer is extended automatically."
       (let ((try-ccl-compile t)
 	    (prog (eval (ad-get-arg 1))))
-	(ad-set-arg 1 (` '(, prog)))
+	(ad-set-arg 1 `',prog)
 	(while try-ccl-compile
 	  (setq try-ccl-compile nil)
 	  (condition-case sig
@@ -86,12 +86,12 @@ Value is a list of transformed arguments
 	    (setq properties (plist-put properties 'pre-write-conversion tmp)))
 	(cond
 	 ((eq type 'shift-jis)
-	  (` ((, name) 1 (, mnemonic) (, doc-string)
-	      nil (, properties) (, eol-type))))
+	  `(,name 1 ,mnemonic ,doc-string
+		  nil ,properties ,eol-type))
 	 ((eq type 'iso2022) ; This is not perfect.
 	  (if (plist-get props 'escape-quoted)
 	      (error "escape-quoted is not supported: %S"
-		     (` ((, name) (, type) (, doc-string) (, props)))))
+		     `(,name ,type ,doc-string ,props)))
 	  (let ((g0 (plist-get props 'charset-g0))
 		(g1 (plist-get props 'charset-g1))
 		(g2 (plist-get props 'charset-g2))
@@ -114,43 +114,43 @@ Value is a list of transformed arguments
 		      'japanese-jisx0208-1978))))
 	    (if (charsetp g0)
 		(if (plist-get props 'force-g0-on-output)
-		    (setq g0 (` (nil (, g0))))
-		  (setq g0 (` ((, g0) t)))))
+		    (setq g0 `(nil ,g0))
+		  (setq g0 `(,g0 t))))
 	    (if (charsetp g1)
 		(if (plist-get props 'force-g1-on-output)
-		    (setq g1 (` (nil (, g1))))
-		  (setq g1 (` ((, g1) t)))))
+		    (setq g1 `(nil ,g1))
+		  (setq g1 `(,g1 t))))
 	    (if (charsetp g2)
 		(if (plist-get props 'force-g2-on-output)
-		    (setq g2 (` (nil (, g2))))
-		  (setq g2 (` ((, g2) t)))))
+		    (setq g2 `(nil ,g2))
+		  (setq g2 `(,g2 t))))
 	    (if (charsetp g3)
 		(if (plist-get props 'force-g3-on-output)
-		    (setq g3 (` (nil (, g3))))
-		  (setq g3 (` ((, g3) t)))))
-	    (` ((, name) 2 (, mnemonic) (, doc-string)
-		((, g0) (, g1) (, g2) (, g3)
-		 (, (plist-get props 'short))
-		 (, (not (plist-get props 'no-ascii-eol)))
-		 (, (not (plist-get props 'no-ascii-cntl)))
-		 (, (plist-get props 'seven))
-		 t
-		 (, (not (plist-get props 'lock-shift)))
-		 (, use-roman)
-		 (, use-oldjis)
-		 (, (plist-get props 'no-iso6429))
-		 nil nil nil nil)
-		(, properties) (, eol-type)))))
-	 ((eq type 'big5)
-	  (` ((, name) 3 (, mnemonic) (, doc-string)
-	      nil (, properties) (, eol-type))))
+		    (setq g3 `(nil ,g3))
+		  (setq g3 `(,g3 t))))
+	    `(,name 2 ,mnemonic ,doc-string
+		    (,g0 ,g1 ,g2 ,g3
+			 ,(plist-get props 'short)
+			 ,(not (plist-get props 'no-ascii-eol))
+			 ,(not (plist-get props 'no-ascii-cntl))
+			 ,(plist-get props 'seven)
+			 t
+			 ,(not (plist-get props 'lock-shift))
+			 ,use-roman
+			 ,use-oldjis
+			 ,(plist-get props 'no-iso6429)
+			 nil nil nil nil)
+		    ,properties ,eol-type)))
+	  ((eq type 'big5)
+	   `(,name 3 ,mnemonic ,doc-string
+		   nil ,properties ,eol-type))
 	 ((eq type 'ccl)
-	  (` ((, name) 4 (, mnemonic) (, doc-string)
-	      ((, (plist-get props 'decode)) . (, (plist-get props 'encode)))
-	      (, properties) (, eol-type))))
+	  `(,name 4 ,mnemonic ,doc-string
+		  (,(plist-get props 'decode) . ,(plist-get props 'encode))
+		  ,properties ,eol-type))
 	 (t
 	  (error "unsupported XEmacs style make-coding-style arguments: %S"
-		 (` ((, name) (, type) (, doc-string) (, props))))))))
+		 `(,name ,type ,doc-string ,props))))))
     (defadvice make-coding-system
       (before ccl-compat (name type &rest ad-subr-args) activate)
       "Emulate XEmacs style make-coding-system."
