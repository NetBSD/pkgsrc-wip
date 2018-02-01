$NetBSD: patch-poe.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

(1)
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
(2)
Fix following problem for emacs-26 (25.1.50)
Loading `poe': old-style backquotes detected!
Invalid read syntax: "Expected opening brace after \\N"
gmake: *** [Makefile:31: elc] Error 255

--- poe.el.orig	2016-12-26 16:51:28.000000000 +0900
+++ poe.el	2018-02-01 12:51:58.483310399 +0900
@@ -916,20 +916,20 @@ APEL provides this as dummy for compatib
 (defmacro-maybe save-current-buffer (&rest body)
   "Save the current buffer; execute BODY; restore the current buffer.
 Executes BODY just like `progn'."
-  (` (let ((orig-buffer (current-buffer)))
+  `(let ((orig-buffer (current-buffer)))
        (unwind-protect
 	   (progn (,@ body))
 	 (if (buffer-live-p orig-buffer)
-	     (set-buffer orig-buffer))))))
+	     (set-buffer orig-buffer)))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-current-buffer BUFFER &rest BODY)
 (defmacro-maybe with-current-buffer (buffer &rest body)
   "Execute the forms in BODY with BUFFER as the current buffer.
 The value returned is the value of the last form in BODY.
 See also `with-temp-buffer'."
-  (` (save-current-buffer
+  `(save-current-buffer
        (set-buffer (, buffer))
-       (,@ body))))
+       (,@ body)))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-temp-file FILE &rest FORMS)
 (defmacro-maybe with-temp-file (file &rest forms)
@@ -938,7 +938,7 @@ The value of the last form in FORMS is r
 See also `with-temp-buffer'."
   (let ((temp-file (make-symbol "temp-file"))
 	(temp-buffer (make-symbol "temp-buffer")))
-    (` (let (((, temp-file) (, file))
+    `(let (((, temp-file) (, file))
 	     ((, temp-buffer)
 	      (get-buffer-create (generate-new-buffer-name " *temp file*"))))
 	 (unwind-protect
@@ -949,7 +949,7 @@ See also `with-temp-buffer'."
 		 (widen)
 		 (write-region (point-min) (point-max) (, temp-file) nil 0)))
 	   (and (buffer-name (, temp-buffer))
-		(kill-buffer (, temp-buffer))))))))
+		(kill-buffer (, temp-buffer)))))))
 
 ;; Emacs 20.4 and later: (with-temp-message MESSAGE &rest BODY)
 ;; This macro uses `current-message', which appears in v20.
@@ -965,7 +965,7 @@ If MESSAGE is nil, the echo area and mes
 Use a MESSAGE of \"\" to temporarily clear the echo area."
     (let ((current-message (make-symbol "current-message"))
 	  (temp-message (make-symbol "with-temp-message")))
-      (` (let (((, temp-message) (, message))
+      `(let (((, temp-message) (, message))
 	       ((, current-message)))
 	   (unwind-protect
 	       (progn
@@ -974,32 +974,32 @@ Use a MESSAGE of \"\" to temporarily cle
 		   (message "%s" (, temp-message))
 		   (,@ body))
 		 (and (, temp-message) (, current-message)
-		      (message "%s" (, current-message))))))))))
+		      (message "%s" (, current-message)))))))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-temp-buffer &rest FORMS)
 (defmacro-maybe with-temp-buffer (&rest forms)
   "Create a temporary buffer, and evaluate FORMS there like `progn'.
 See also `with-temp-file' and `with-output-to-string'."
   (let ((temp-buffer (make-symbol "temp-buffer")))
-    (` (let (((, temp-buffer)
+    `(let (((, temp-buffer)
 	      (get-buffer-create (generate-new-buffer-name " *temp*"))))
 	 (unwind-protect
 	     (with-current-buffer (, temp-buffer)
 	       (,@ forms))
 	   (and (buffer-name (, temp-buffer))
-		(kill-buffer (, temp-buffer))))))))
+		(kill-buffer (, temp-buffer)))))))
 
 ;; Emacs 20.1/XEmacs 20.3(?) and later: (with-output-to-string &rest BODY)
 (defmacro-maybe with-output-to-string (&rest body)
   "Execute BODY, return the text it sent to `standard-output', as a string."
-  (` (let ((standard-output
+  `(let ((standard-output
 	    (get-buffer-create (generate-new-buffer-name " *string-output*"))))
        (let ((standard-output standard-output))
 	 (,@ body))
        (with-current-buffer standard-output
 	 (prog1
 	     (buffer-string)
-	   (kill-buffer nil))))))
+	   (kill-buffer nil)))))
 
 ;; Emacs 20.1 and later: (combine-after-change-calls &rest BODY)
 (defmacro-maybe combine-after-change-calls (&rest body)
@@ -1081,7 +1081,7 @@ then capitalize each word in NEWTEXT.
 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
   `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\N' means substitute what matched the Nth `\(...\)'.
        If Nth parens didn't match, substitute nothing.
   `\\' means insert one `\'.
 FIXEDCASE and LITERAL are optional arguments.
@@ -1133,7 +1133,7 @@ then capitalize each word in NEWTEXT.
 If third arg LITERAL is non-nil, insert NEWTEXT literally.
 Otherwise treat `\' as special:
   `\&' in NEWTEXT means substitute original matched text.
-  `\N' means substitute what matched the Nth `\(...\)'.
+  `\\N' means substitute what matched the Nth `\(...\)'.
        If Nth parens didn't match, substitute nothing.
   `\\' means insert one `\'.
 FIXEDCASE and LITERAL are optional arguments.
@@ -1667,7 +1667,7 @@ See `walk-windows' for the meaning of MI
                      )))
       ;; arglist: (prefix &optional dir-flag suffix)
       (cond
-       ((not arglist)
+       ((or (not arglist) (not (listp arglist)))
         ;; `make-temp-file' is a built-in; expects 3-args.
         (put 'make-temp-file 'defun-maybe '3-args))
        ((> (length arglist) 3)
