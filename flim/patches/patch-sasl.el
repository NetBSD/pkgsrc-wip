$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./sasl.el	2005-07-06 11:09:05.000000000 +0900
+++ ././sasl.el	2020-09-05 16:02:39.902101886 +0900
@@ -1,4 +1,4 @@
-;;; sasl.el --- SASL client framework
+;;; sasl.el --- SASL client framework  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 2000 Free Software Foundation, Inc.
 
@@ -36,18 +36,30 @@
 
 ;;; Code:
 
-(defvar sasl-mechanisms
-  '("CRAM-MD5" "DIGEST-MD5" "PLAIN" "LOGIN" "ANONYMOUS"
-    "NTLM" "SCRAM-MD5"))
+(defvar sasl-additional-mechanism-alist
+  '((sasl-scram-rfc "SCRAM-SHA-1")
+    (sasl-scram-sha256 "SCRAM-SHA-256")))
 
 (defvar sasl-mechanism-alist
-  '(("CRAM-MD5" sasl-cram)
-    ("DIGEST-MD5" sasl-digest)
-    ("PLAIN" sasl-plain)
-    ("LOGIN" sasl-login)
-    ("ANONYMOUS" sasl-anonymous)
-    ("NTLM" sasl-ntlm)
-    ("SCRAM-MD5" sasl-scram)))
+  (append '(("CRAM-MD5" sasl-cram)
+	    ("DIGEST-MD5" sasl-digest)
+	    ("PLAIN" sasl-plain)
+	    ("LOGIN" sasl-login)
+	    ("ANONYMOUS" sasl-anonymous)
+	    ("NTLM" sasl-ntlm)
+	    ("SCRAM-MD5" sasl-scram)
+	    ("OAUTHBEARER" sasl-xoauth2)
+	    ("XOAUTH2" sasl-xoauth2))
+	  (let (result)
+	    (mapc (lambda (elt)
+		    (when (locate-library (symbol-name (car elt)))
+		      (dolist (name (cdr elt))
+			(setq result (cons (list name (car elt)) result)))))
+		  sasl-additional-mechanism-alist)
+	    result)))
+
+(defvar sasl-mechanisms
+  (mapcar 'car sasl-mechanism-alist))
 
 (defvar sasl-unique-id-function #'sasl-unique-id-function)
 
@@ -204,14 +216,13 @@
 	(= len 0))
       ""
     (concat (sasl-unique-id-number-base36 (/ num 36) (1- len))
-	    (char-to-string (aref "zyxwvutsrqponmlkjihgfedcba9876543210"
-				  (% num 36))))))
+	    (list (aref "zyxwvutsrqponmlkjihgfedcba9876543210" (% num 36))))))
 
 ;;; PLAIN (RFC2595 Section 6)
 (defconst sasl-plain-steps
   '(sasl-plain-response))
 
-(defun sasl-plain-response (client step)
+(defun sasl-plain-response (client _step)
   (let ((passphrase
 	 (sasl-read-passphrase
 	  (format "PLAIN passphrase for %s: " (sasl-client-name client))))
@@ -237,12 +248,12 @@
     sasl-login-response-1
     sasl-login-response-2))
 
-(defun sasl-login-response-1 (client step)
+(defun sasl-login-response-1 (client _step)
 ;;;  (unless (string-match "^Username:" (sasl-step-data step))
 ;;;    (sasl-error (format "Unexpected response: %s" (sasl-step-data step))))
   (sasl-client-name client))
 
-(defun sasl-login-response-2 (client step)
+(defun sasl-login-response-2 (client _step)
 ;;;  (unless (string-match "^Password:" (sasl-step-data step))
 ;;;    (sasl-error (format "Unexpected response: %s" (sasl-step-data step))))
   (sasl-read-passphrase
@@ -258,7 +269,7 @@
   '(ignore				;no initial response
     sasl-anonymous-response))
 
-(defun sasl-anonymous-response (client step)
+(defun sasl-anonymous-response (client _step)
   (or (sasl-client-property client 'trace)
       (sasl-client-name client)))
 
