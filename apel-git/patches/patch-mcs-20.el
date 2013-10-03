$NetBSD: patch-mcs-20.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- mcs-20.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ mcs-20.el	2013-10-03 19:33:10.000000000 +0900
@@ -84,11 +84,13 @@ is specified, it is used as line break c
   (if (stringp charset)
       (setq charset (intern (downcase charset)))
     )
-  (let ((cs (assq charset mime-charset-coding-system-alist)))
-    (setq cs
-	  (if cs
-	      (cdr cs)
-	    charset))
+  (let ((cs (cdr (assq charset mime-charset-coding-system-alist))))
+    (unless (or (null cs) (find-coding-system cs))
+      (message
+       "Invalid coding system: %s.  Confirm mime-charset-coding-system-alist."
+       cs)
+      (setq cs nil))
+    (unless cs (setq cs charset))
     (if lbt
 	(setq cs (intern (format "%s-%s" cs
 				 (cond ((eq lbt 'CRLF) 'dos)
@@ -96,12 +98,11 @@ is specified, it is used as line break c
 				       ((eq lbt 'CR) 'mac)
 				       (t lbt)))))
       )
-    (if (find-coding-system cs)
-	cs
-      (if mime-charset-to-coding-system-default-method
-	  (funcall mime-charset-to-coding-system-default-method
-		   charset lbt cs)
-	))))
+    (or (find-coding-system cs)
+	(if mime-charset-to-coding-system-default-method
+	    (funcall mime-charset-to-coding-system-default-method
+		     charset lbt cs)
+	  ))))
 
 (defalias 'mime-charset-p 'mime-charset-to-coding-system)
 
@@ -209,6 +210,34 @@ It must be symbol."
 	(setq rest (cdr rest)))
       default-mime-charset-for-write)))
 )
+
+((eval-when-compile (and (boundp 'mule-version)
+			 (null (string< mule-version "6.0"))))
+;; for Emacs 23 and later
+(defun detect-mime-charset-string (string)
+  "Return MIME charset for STRING."
+  (let ((src (string-to-list string))
+	tmp)
+    (setq tmp src)
+    ;; Uniquify the list of characters.
+    (while tmp
+      (setq tmp (setcdr tmp (delq (car tmp) (cdr tmp)))))
+    ;; Detect charset from the list of characters.
+    (catch 'found
+      (mapc (lambda (cons)
+	      (catch 'next
+		(mapc (lambda (ch) (unless (char-charset ch (car cons))
+				     (throw 'next nil)))
+		      src)
+		(throw 'found (cdr cons))))
+	    charsets-mime-charset-alist)
+      default-mime-charset-for-write)))
+
+(defsubst detect-mime-charset-region (start end)
+  "Return MIME charset for region between START and END."
+  (detect-mime-charset-string
+   (buffer-substring-no-properties start end))))
+
 (t
 ;; for legacy Mule
 (defun detect-mime-charset-region (start end)
