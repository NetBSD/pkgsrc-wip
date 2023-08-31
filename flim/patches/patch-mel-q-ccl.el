$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./mel-q-ccl.el	2006-06-13 00:10:02.000000000 +0900
+++ ././mel-q-ccl.el	2020-09-05 16:02:39.899821151 +0900
@@ -1,4 +1,4 @@
-;;; mel-q-ccl.el --- Quoted-Printable encoder/decoder using CCL.
+;;; mel-q-ccl.el --- Quoted-Printable encoder/decoder using CCL.  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1998,1999 Tanaka Akira
 
@@ -67,7 +67,7 @@
       0   1   2   3   4   5   6   7   8   9 nil nil nil nil nil nil
     nil  10  11  12  13  14  15 nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
-    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
+    nil  10  11  12  13  14  15 nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
     nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
@@ -133,9 +133,7 @@
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
    enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc
-   enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc])
-
-)
+   enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc enc]))
 
 
 ;;; @ CCL programs
@@ -146,13 +144,14 @@
 (define-ccl-program mel-ccl-decode-q
   `(1
     ((loop
-      (read-branch
-       r0
+      (read r0)
+      (branch
+       (r0 & 255)
        ,@(mapcar
           (lambda (r0)
             (cond
              ((= r0 (char-int ?_))
-              `(write-repeat ? ))
+              `(write-repeat ?\s))
              ((= r0 (char-int ?=))
               `((loop
                  (read-branch
@@ -188,7 +187,9 @@
   `(3
     (loop
      (loop
-      (read-branch
+      (read r0)
+      (r0 &= 255)
+      (branch
        r0
        ,@(mapcar
           (lambda (r0)
@@ -214,9 +215,7 @@
 	    (if (or (= r1 32) (member r1 raw))
 		'((r0 += 1) (repeat))
 	      '((r0 += 3) (repeat))))
-	  mel-ccl-256-table))))))
-
-)
+	  mel-ccl-256-table)))))))
 
 (define-ccl-program mel-ccl-encode-uq
   (mel-ccl-encode-q-generic mel-ccl-u-raw))
@@ -243,9 +242,7 @@
     (unless p
       (setq p (cons branch (length eof-block-branches))
 	    eof-block-branches (cons p eof-block-branches)))
-    `(,eof-block-reg = ,(cdr p))))
-
-)
+    `(,eof-block-reg = ,(cdr p)))))
 
 (eval-when-compile
 
@@ -265,9 +262,7 @@
     `(,(mel-ccl-set-eof-block crlf-eof)
       (read-if (,reg == ?\n)
 	,succ
-	,crlf-fail))))
-
-)
+	,crlf-fail)))))
 
 (eval-when-compile
 
@@ -281,12 +276,10 @@
 	(after-wsp 'r5)
 	(column 'r6)
 	(type 'r3)
-	(current 'r0)
 	(type-raw 0)
 	(type-enc 1)
 	(type-wsp 2)
-	(type-brk 3)
-	)
+	(type-brk 3))
     `(4
       ((,column = 0)
        (,after-wsp = 0)
@@ -295,6 +288,7 @@
        (loop	; invariant: column <= 75
 	(loop
 	 (loop
+	  (r0 &= 255)
 	  (branch
 	   r0
 	   ,@(mapcar
@@ -310,7 +304,7 @@
 			       (,(mel-ccl-set-eof-block '((write "Fro") (end)))
 				(read-if (r0 == ?m)
 				  (,(mel-ccl-set-eof-block '((write "From") (end)))
-				   (read-if (r0 == ? )
+				   (read-if (r0 == ?\s)
 				     ((,column = 7)
 				      (,after-wsp = 1)
 				      ,(mel-ccl-set-eof-block '((write "From=20") (end)))
@@ -359,8 +353,7 @@
 		   ((eq tmp 'cr) `((,type = ,(if input-crlf type-brk type-enc))
 				   (break)))
 		   ((eq tmp 'lf) `((,type = ,(if input-crlf type-enc type-brk))
-				   (break)))
-		   )))
+				   (break))))))
 	      mel-ccl-256-table)))
 	 ;; r0:type{raw,enc,wsp,brk}
 	 (branch
@@ -580,8 +573,7 @@
 		 (,column = 0)
 		 ,@(if output-crlf '((write ?\r)) '())
 		 ,(mel-ccl-set-eof-block `(end))
-		 (write-read-repeat r0)))
-	     )))))
+		 (write-read-repeat r0))))))))
       (branch
        ,eof-block-reg
        ,@(reverse (mapcar 'car eof-block-branches))))))
@@ -591,13 +583,13 @@
     ((read r0)
      (loop
       (branch
-       r0
+       (r0 & 255)
        ,@(mapcar
           (lambda (r0)
             (let ((tmp (aref mel-ccl-qp-table r0)))
               (cond
                ((eq tmp 'raw) `(write-read-repeat r0))
-               ((eq tmp 'wsp) (if (eq r0 (char-int ? ))
+               ((eq tmp 'wsp) (if (eq r0 (char-int ?\s))
                                   `(r1 = 1)
                                 `(r1 = 0)))
                ((eq tmp 'cr)
@@ -639,7 +631,7 @@
                 `((read r0)
                   ;; '=' r0
                   (r1 = (r0 == ?\t))
-                  (if ((r0 == ? ) | r1)
+                  (if ((r0 == ?\s) | r1)
                       ;; '=' r0:[\t ]
                       ;; Skip transport-padding.
                       ;; It should check CR LF after
@@ -647,7 +639,7 @@
                       (loop
                        (read-if (r0 == ?\t)
                                 (repeat)
-                                (if (r0 == ? )
+                                (if (r0 == ?\s)
                                     (repeat)
                                   (break)))))
                   ;; '=' [\t ]* r0:[^\t ]
@@ -729,9 +721,8 @@
                (t
                 ;; r0:[^\t\r -~]
                 ;; invalid character found.
-                ;; -> ignore.
-                `((read r0)
-                  (repeat))))))
+                ;; -> output as is.
+                `((write-read-repeat r0))))))
           mel-ccl-256-table))
       ;; r1[0]:[\t ]
       (loop
@@ -807,10 +798,7 @@
 			(repeat))))
 		mel-ccl-28-table))))
 	  '(0 1 2 3 4)))
-      (repeat)
-      ))))
-
-)
+      (repeat))))))
 
 (define-ccl-program mel-ccl-encode-quoted-printable-crlf-crlf
   (mel-ccl-encode-quoted-printable-generic t t))
@@ -902,7 +890,7 @@
      (decode-coding-string
       (with-temp-buffer
 	(set-buffer-multibyte nil)
-	(insert-file-contents-as-binary filename)
+	(insert-file-contents-literally filename)
 	(buffer-string))
       'mel-ccl-quoted-printable-lf-lf-rev)))
 
@@ -914,8 +902,7 @@
    'quoted-printable-ccl-encode-region)
   (mel-define-method-function
    (mime-insert-encoded-file filename (nil "quoted-printable"))
-   'quoted-printable-ccl-insert-encoded-file)
-  )
+   'quoted-printable-ccl-insert-encoded-file))
 
 (defun quoted-printable-ccl-decode-string (string)
   "Decode quoted-printable encoded STRING."
@@ -932,7 +919,11 @@
 (defun quoted-printable-ccl-write-decoded-region (start end filename)
   "Decode quoted-printable encoded current region and write out to FILENAME."
   (interactive "*r\nFWrite decoded region to file: ")
-  (let ((coding-system-for-write 'mel-ccl-quoted-printable-lf-lf-rev)
+  (defvar jam-zcat-filename-list)
+  (let ((coding-system-for-write
+	 (if (coding-system-p 'mel-ccl-quoted-printable-lf-lf-rev-unix)
+	     'mel-ccl-quoted-printable-lf-lf-rev-unix
+	   'mel-ccl-quoted-printable-lf-lf-rev))
 	jka-compr-compression-info-list jam-zcat-filename-list)
     (write-region start end filename)))
 
@@ -967,19 +958,17 @@
    string
    'mel-ccl-uq-rev))
 
-(unless (featurep 'xemacs)
-  (defun q-encoding-ccl-encoded-length (string &optional mode)
-    (let ((status [nil nil nil nil nil nil nil nil nil]))
-      (fillarray status nil)		; XXX: Is this necessary?
-      (ccl-execute-on-string
-       (cond
-	((eq mode 'text) 'mel-ccl-count-uq)
-	((eq mode 'comment) 'mel-ccl-count-cq)
-	(t 'mel-ccl-count-pq))
-       status
-       string)
-      (aref status 0)))
-  )
+(defun q-encoding-ccl-encoded-length (string &optional mode)
+  (let ((status [nil nil nil nil nil nil nil nil nil]))
+    (fillarray status nil)		; XXX: Is this necessary?
+    (ccl-execute-on-string
+     (cond
+      ((eq mode 'text) 'mel-ccl-count-uq)
+      ((eq mode 'comment) 'mel-ccl-count-cq)
+      (t 'mel-ccl-count-pq))
+     status
+     string)
+    (aref status 0)))
 
 (mel-define-method-function (encoded-text-encode-string string (nil "Q"))
 			    'q-encoding-ccl-encode-string)
