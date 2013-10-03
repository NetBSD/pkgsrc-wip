$NetBSD: patch-filename.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- filename.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ filename.el	2013-10-03 19:33:10.000000000 +0900
@@ -102,26 +102,26 @@ Moreover, if you want to convert Japanes
 		inc-i '(1+ i))
 	(setq sref 'aref
 	      inc-i '(+ i (char-length chr))))
-      (` (let ((len (length (, string)))
-	       (b 0)(i 0)
-	       (dest ""))
-	   (while (< i len)
-	     (let ((chr ((, sref) (, string) i))
-		   (lst filename-replacement-alist)
-		   ret)
-	       (while (and lst (not ret))
-		 (if (if (functionp (car (car lst)))
-			 (setq ret (funcall (car (car lst)) chr))
-		       (setq ret (memq chr (car (car lst)))))
-		     t			; quit this loop.
-		   (setq lst (cdr lst))))
-	       (if ret
-		   (setq dest (concat dest (substring (, string) b i)
-				      (cdr (car lst)))
-			 i (, inc-i)
-			 b i)
-		 (setq i (, inc-i)))))
-	   (concat dest (substring (, string) b)))))))
+      `(let ((len (length ,string))
+	     (b 0)(i 0)
+	     (dest ""))
+	 (while (< i len)
+	   (let ((chr (,sref ,string i))
+		 (lst filename-replacement-alist)
+		 ret)
+	     (while (and lst (not ret))
+	       (if (if (functionp (car (car lst)))
+		       (setq ret (funcall (car (car lst)) chr))
+		     (setq ret (memq chr (car (car lst)))))
+		   t			; quit this loop.
+		 (setq lst (cdr lst))))
+	     (if ret
+		 (setq dest (concat dest (substring ,string b i)
+				    (cdr (car lst)))
+		       i ,inc-i
+		       b i)
+	       (setq i ,inc-i))))
+	 (concat dest (substring ,string b))))))
 
 (defun filename-special-filter (string)
   (filename-special-filter-1 string))
