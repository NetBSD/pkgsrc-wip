$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./mmgeneric.el	2005-07-06 11:09:05.000000000 +0900
+++ ././mmgeneric.el	2020-09-05 16:02:39.901580357 +0900
@@ -1,4 +1,4 @@
-;;; mmgeneric.el --- MIME generic entity module
+;;; mmgeneric.el --- MIME generic entity module  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1995,96,97,98,99,2000 Free Software Foundation, Inc.
 
@@ -50,8 +50,7 @@
 		      ;; for other fields
 		      original-header parsed-header))
 
-  (luna-define-internal-accessors 'mime-entity)
-  )
+  (luna-define-internal-accessors 'mime-entity))
 
 (defalias 'mime-entity-representation-type-internal 'luna-class-name)
 (defalias 'mime-entity-set-representation-type-internal 'luna-set-class-name)
@@ -70,8 +69,7 @@
 				    (mime-entity-content-type entity)
 				    "charset")
 				   default-mime-charset)
-			       'CRLF)
-   ))
+			       'CRLF)))
 
 
 ;;; @ for mm-backend
@@ -83,8 +81,7 @@
 (defmacro mm-define-backend (type &optional parents)
   `(luna-define-class ,(mm-expand-class-name type)
 		      ,(nconc (mapcar (lambda (parent)
-					(mm-expand-class-name parent)
-					)
+					(mm-expand-class-name parent))
 				      parents)
 			      '(mime-entity))))
 
@@ -96,8 +93,7 @@
 	  (cons (list (car spec)
 		      (mm-expand-class-name (nth 1 spec)))
 		(cdr args)))
-    `(luna-define-method ,name ,args ,@body)
-    ))
+    `(luna-define-method ,name ,args ,@body)))
 
 (put 'mm-define-method 'lisp-indent-function 'defun)
 
@@ -105,8 +101,7 @@
   (&define name ((arg symbolp)
 		 [&rest arg]
 		 [&optional ["&optional" arg &rest arg]]
-		 &optional ["&rest" arg]
-		 )
+		 &optional ["&rest" arg])
 	   def-body))
 
 
@@ -121,18 +116,14 @@
 	(while visible-fields
 	  (let ((regexp (car visible-fields)))
 	    (if (string-match regexp field-name)
-		(throw 'found t)
-	      ))
-	  (setq visible-fields (cdr visible-fields))
-	  ))
+		(throw 'found t)))
+	  (setq visible-fields (cdr visible-fields))))
       (catch 'found
 	(while invisible-fields
 	  (let ((regexp (car invisible-fields)))
 	    (if (string-match regexp field-name)
-		(throw 'found nil)
-	      ))
-	  (setq invisible-fields (cdr invisible-fields))
-	  )
+		(throw 'found nil)))
+	  (setq invisible-fields (cdr invisible-fields)))
 	t)))
 
 (defun mime-insert-header-from-buffer (buffer start end
@@ -142,8 +133,7 @@
 	(mode-obj (mime-find-field-presentation-method 'wide))
 	field-decoder
 	f-b p f-e field-name len field field-body)
-    (save-excursion
-      (set-buffer buffer)
+    (with-current-buffer buffer
       (save-restriction
 	(narrow-to-region start end)
 	(goto-char start)
@@ -166,8 +156,7 @@
 			  (funcall field-decoder field-body len)
 			;; Don't decode
 			field-body))
-	      (insert "\n")
-	      )))))))
+	      (insert "\n"))))))))
 
 
 ;;; @ end
