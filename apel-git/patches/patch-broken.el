$NetBSD: patch-broken.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- broken.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ broken.el	2013-10-03 19:33:10.000000000 +0900
@@ -58,51 +58,51 @@ FACILITY must be symbol.
 
 If ASSERTION is not omitted and evaluated to nil and NO-NOTICE is nil,
 it is noticed."
-  (` (static-if (, assertion)
-	 (eval-and-compile
-	   (broken-facility-internal '(, facility) (, docstring) t))
-       (eval-when-compile
-	 (when (and '(, assertion) (not '(, no-notice))
-		    notice-non-obvious-broken-facility)
-	   (message "BROKEN FACILITY DETECTED: %s" (, docstring)))
-	 nil)
-       (eval-and-compile
-	 (broken-facility-internal '(, facility) (, docstring) nil)))))
+  `(static-if ,assertion
+	      (eval-and-compile
+		(broken-facility-internal ',facility ,docstring t))
+	      (eval-when-compile
+		(when (and ',assertion (not ',no-notice)
+			   notice-non-obvious-broken-facility)
+		  (message "BROKEN FACILITY DETECTED: %s" ,docstring))
+		nil)
+	      (eval-and-compile
+		(broken-facility-internal ',facility ,docstring nil))))
 
 (put 'if-broken 'lisp-indent-function 2)
 (defmacro if-broken (facility then &rest else)
   "If FACILITY is broken, expand to THEN, otherwise (progn . ELSE)."
-  (` (static-if (broken-p '(, facility))
-	 (, then)
-       (,@ else))))
+  `(static-if (broken-p ',facility)
+	      ,then
+	      ,@else))
 
 
 (put 'when-broken 'lisp-indent-function 1)
 (defmacro when-broken (facility &rest body)
   "If FACILITY is broken, expand to (progn . BODY), otherwise nil."
-  (` (static-when (broken-p '(, facility))
-       (,@ body))))
+  `(static-when (broken-p ',facility)
+		,@body))
 
 (put 'unless-broken 'lisp-indent-function 1)
 (defmacro unless-broken (facility &rest body)
   "If FACILITY is not broken, expand to (progn . BODY), otherwise nil."
-  (` (static-unless (broken-p '(, facility))
-       (,@ body))))
+  `(static-unless (broken-p ',facility)
+		  ,@ body))
 
 (defmacro check-broken-facility (facility)
   "Check FACILITY is broken or not. If the status is different on
 compile(macro expansion) time and run time, warn it."
-  (` (if-broken (, facility)
-	 (unless (broken-p '(, facility))
-	   (message "COMPILE TIME ONLY BROKEN FACILITY DETECTED: %s" 
-		    (or
-		     '(, (broken-facility-description facility))
-		     (broken-facility-description '(, facility)))))
-       (when (broken-p '(, facility))
-	 (message "RUN TIME ONLY BROKEN FACILITY DETECTED: %s" 
-		  (or
-		   (broken-facility-description '(, facility))
-		   '(, (broken-facility-description facility))))))))
+  `(if-broken ,facility
+	      (unless (broken-p ',facility)
+		(message "COMPILE TIME ONLY BROKEN FACILITY DETECTED: %s" 
+			 (or
+			  ',(broken-facility-description facility)
+			  (broken-facility-description ',facility))))
+	      (when (broken-p ',facility)
+		(message "RUN TIME ONLY BROKEN FACILITY DETECTED: %s" 
+			 (or
+			  (broken-facility-description ',facility)
+			  ', (broken-facility-description facility))))))
 
 
 ;;; @ end
