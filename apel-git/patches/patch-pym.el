$NetBSD: patch-pym.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- pym.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ pym.el	2013-10-03 19:33:10.000000000 +0900
@@ -62,32 +62,32 @@
   "Define NAME as a function if NAME is not defined.
 See also the function `defun'."
   (or (and (fboundp name)
-	   (not (get name 'defun-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defun (, name) (,@ everything-else))
-	       ;; This `defun' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defun-maybe t))))))
+           (not (get name 'defun-maybe)))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (defun ,name ,@ everything-else)
+             ;; This `defun' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defun-maybe t)))))
 
 (put 'defmacro-maybe 'lisp-indent-function 'defun)
 (defmacro defmacro-maybe (name &rest everything-else)
   "Define NAME as a macro if NAME is not defined.
 See also the function `defmacro'."
   (or (and (fboundp name)
-	   (not (get name 'defmacro-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defmacro (, name) (,@ everything-else))
-	       ;; This `defmacro' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defmacro-maybe t))))))
+           (not (get name 'defmacro-maybe)))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (defmacro ,name ,@ everything-else)
+             ;; This `defmacro' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defmacro-maybe t)))))
 
 (put 'defsubst-maybe 'lisp-indent-function 'defun)
 (defmacro defsubst-maybe (name &rest everything-else)
@@ -95,51 +95,51 @@ See also the function `defmacro'."
 See also the macro `defsubst'."
   (or (and (fboundp name)
 	   (not (get name 'defsubst-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (defsubst (, name) (,@ everything-else))
-	       ;; This `defsubst' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defsubst-maybe t))))))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (defsubst ,name ,@ everything-else)
+             ;; This `defsubst' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defsubst-maybe t)))))
 
 (defmacro defalias-maybe (symbol definition)
   "Define SYMBOL as an alias for DEFINITION if SYMBOL is not defined.
 See also the function `defalias'."
   (setq symbol (eval symbol))
   (or (and (fboundp symbol)
-	   (not (get symbol 'defalias-maybe)))
-      (` (or (fboundp (quote (, symbol)))
-	     (prog1
-		 (defalias (quote (, symbol)) (, definition))
-	       ;; `defalias' updates `load-history' internally.
-	       (put (quote (, symbol)) 'defalias-maybe t))))))
+           (not (get symbol 'defalias-maybe)))
+      `(or (fboundp (quote ,symbol))
+           (prog1
+               (defalias (quote ,symbol) ,definition)
+             ;; `defalias' updates `load-history' internally.
+             (put (quote ,symbol) 'defalias-maybe t)))))
 
 (defmacro defvar-maybe (name &rest everything-else)
   "Define NAME as a variable if NAME is not defined.
 See also the function `defvar'."
   (or (and (boundp name)
 	   (not (get name 'defvar-maybe)))
-      (` (or (boundp (quote (, name)))
-	     (prog1
-		 (defvar (, name) (,@ everything-else))
-	       ;; byte-compiler will generate code to update
-	       ;; `load-history'.
-	       (put (quote (, name)) 'defvar-maybe t))))))
+      `(or (boundp (quote ,name))
+           (prog1
+               (defvar ,name ,@ everything-else)
+             ;; byte-compiler will generate code to update
+             ;; `load-history'.
+             (put (quote ,name) 'defvar-maybe t)))))
 
 (defmacro defconst-maybe (name &rest everything-else)
   "Define NAME as a constant variable if NAME is not defined.
 See also the function `defconst'."
   (or (and (boundp name)
-	   (not (get name 'defconst-maybe)))
-      (` (or (boundp (quote (, name)))
-	     (prog1
-		 (defconst (, name) (,@ everything-else))
-	       ;; byte-compiler will generate code to update
-	       ;; `load-history'.
-	       (put (quote (, name)) 'defconst-maybe t))))))
+           (not (get name 'defconst-maybe)))
+      `(or (boundp (quote ,name))
+           (prog1
+               (defconst ,name ,@ everything-else)
+             ;; byte-compiler will generate code to update
+             ;; `load-history'.
+             (put (quote ,name) 'defconst-maybe t)))))
 
 (defmacro defun-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as a function if NAME is not defined.
@@ -149,29 +149,29 @@ for function definition of NAME.
 See also the function `defun'."
   (or (stringp doc)
       (setq clauses (cons doc clauses)
-	    doc nil))
+            doc nil))
   (or (and (fboundp name)
-	   (not (get name 'defun-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defun (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defun (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defun' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defun-maybe t))))))
+           (not (get name 'defun-maybe)))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (static-cond
+                ,@ (mapcar
+                    (function
+                      (lambda (case)
+                        (list (car case)
+                              (if doc
+                                  `(defun ,name ,args
+                                     ,doc
+                                     ,@ (cdr case))
+                                ` (defun ,name ,args
+                                    ,@ (cdr case))))))
+                     clauses))
+             ;; This `defun' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defun-maybe t)))))
 
 (defmacro defmacro-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as a macro if NAME is not defined.
@@ -184,26 +184,26 @@ See also the function `defmacro'."
 	    doc nil))
   (or (and (fboundp name)
 	   (not (get name 'defmacro-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defmacro (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defmacro (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defmacro' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defmacro-maybe t))))))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (static-cond
+                ,@ (mapcar
+                     (function
+                      (lambda (case)
+                        (list (car case)
+                              (if doc
+                                  `(defmacro ,name ,args
+                                     ,doc
+                                     ,@ (cdr case))
+                                `(defmacro ,name ,args
+                                   ,@ (cdr case))))))
+                     clauses))
+             ;; This `defmacro' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defmacro-maybe t)))))
 
 (defmacro defsubst-maybe-cond (name args &optional doc &rest clauses)
   "Define NAME as an inline function if NAME is not defined.
@@ -213,29 +213,29 @@ for function definition of NAME.
 See also the macro `defsubst'."
   (or (stringp doc)
       (setq clauses (cons doc clauses)
-	    doc nil))
+            doc nil))
   (or (and (fboundp name)
-	   (not (get name 'defsubst-maybe)))
-      (` (or (fboundp (quote (, name)))
-	     (prog1
-		 (static-cond
-		  (,@ (mapcar
-		       (function
-			(lambda (case)
-			  (list (car case)
-				(if doc
-				    (` (defsubst (, name) (, args)
-					 (, doc)
-					 (,@ (cdr case))))
-				  (` (defsubst (, name) (, args)
-				       (,@ (cdr case))))))))
-		       clauses)))
-	       ;; This `defsubst' will be compiled to `fset',
-	       ;; which does not update `load-history'.
-	       ;; We must update `current-load-list' explicitly.
-	       (setq current-load-list
-		     (cons (quote (, name)) current-load-list))
-	       (put (quote (, name)) 'defsubst-maybe t))))))
+           (not (get name 'defsubst-maybe)))
+      `(or (fboundp (quote ,name))
+           (prog1
+               (static-cond
+                ,@ (mapcar
+                     (function
+                      (lambda (case)
+                        (list (car case)
+                              (if doc
+                                  `(defsubst ,name ,args
+                                     ,doc
+                                     ,@ (cdr case))
+                                `(defsubst ,name ,args
+                                   ,@ (cdr case))))))
+                     clauses))
+             ;; This `defsubst' will be compiled to `fset',
+             ;; which does not update `load-history'.
+             ;; We must update `current-load-list' explicitly.
+             (setq current-load-list
+                   (cons (quote ,name) current-load-list))
+             (put (quote ,name) 'defsubst-maybe t)))))
 
 
 ;;; Edebug spec.
@@ -246,7 +246,7 @@ See also the macro `defsubst'."
   "Set the edebug-form-spec property of SYMBOL according to SPEC.
 Both SYMBOL and SPEC are unevaluated. The SPEC can be 0, t, a symbol
 \(naming a function\), or a list."
-  (` (put (quote (, symbol)) 'edebug-form-spec (quote (, spec)))))
+  `(put (quote ,symbol) 'edebug-form-spec (quote ,spec)))
 
 ;; edebug-spec for `def*-maybe' macros.
 (def-edebug-spec defun-maybe defun)
