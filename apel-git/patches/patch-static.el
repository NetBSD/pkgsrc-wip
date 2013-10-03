$NetBSD: patch-static.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- static.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ static.el	2013-10-03 19:33:10.000000000 +0900
@@ -29,38 +29,39 @@
   "Like `if', but evaluate COND at compile time."
   (if (eval cond)
       then
-    (` (progn  (,@ else)))))
+    `(progn ,@ else)))
 
 (put 'static-when 'lisp-indent-function 1)
 (defmacro static-when (cond &rest body)
   "Like `when', but evaluate COND at compile time."
   (if (eval cond)
-      (` (progn (,@ body)))))
+      `(progn ,@ body)))
 
 (put 'static-unless 'lisp-indent-function 1)
 (defmacro static-unless (cond &rest body)
   "Like `unless', but evaluate COND at compile time."
   (if (eval cond)
       nil
-    (` (progn (,@ body)))))
+    `(progn ,@ body)))
 
 (put 'static-condition-case 'lisp-indent-function 2)
 (defmacro static-condition-case (var bodyform &rest handlers)
   "Like `condition-case', but evaluate BODYFORM at compile time."
-  (eval (` (condition-case (, var)
-	       (list (quote quote) (, bodyform))
-	     (,@ (mapcar
-		  (if var
-		      (function
-		       (lambda (h)
-			 (` ((, (car h))
-			     (list (quote funcall)
-				   (function (lambda ((, var)) (,@ (cdr h))))
-				   (list (quote quote) (, var)))))))
-		    (function
-		     (lambda (h)
-		       (` ((, (car h)) (quote (progn (,@ (cdr h)))))))))
-		  handlers))))))
+  (eval `(condition-case ,var
+             (list (quote quote) ,bodyform)
+           ,@
+           (mapcar
+            (if var
+                (function
+                 (lambda (h)
+                   `(,(car h)
+                     (list (quote funcall)
+                           (function (lambda (,var) ,@ (cdr h)))
+                           (list (quote quote) ,var)))))
+              (function
+               (lambda (h)
+                 `(,(car h) (quote (progn ,@ (cdr h)))))))
+            handlers))))
 
 (put 'static-defconst 'lisp-indent-function 'defun)
 (defmacro static-defconst (symbol initvalue &optional docstring)
@@ -68,8 +69,8 @@
 
 The variable SYMBOL can be referred at both compile time and run time."
   (let ((value (eval initvalue)))
-    (eval (` (defconst (, symbol) (quote (, value)) (, docstring))))
-    (` (defconst (, symbol) (quote (, value)) (, docstring)))))
+    (eval `(defconst ,symbol (quote ,value) ,docstring))
+    `(defconst ,symbol (quote ,value) ,docstring)))
 
 (defmacro static-cond (&rest clauses)
   "Like `cond', but evaluate CONDITION part of each clause at compile time."
