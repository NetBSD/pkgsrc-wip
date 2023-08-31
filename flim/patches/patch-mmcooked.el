$NetBSD$

sync to  lexical-binding

--- /tmp/wip/flim/work/flim-1.14.9/./mmcooked.el	2005-07-06 11:09:05.000000000 +0900
+++ ././mmcooked.el	2020-09-05 16:02:39.901426573 +0900
@@ -1,4 +1,4 @@
-;;; mmcooked.el --- MIME entity implementation for binary buffer
+;;; mmcooked.el --- MIME entity implementation for binary buffer  -*- lexical-binding: t -*-
 
 ;; Copyright (C) 1998,1999 Free Software Foundation, Inc.
 
@@ -28,11 +28,10 @@
 
 (mm-define-backend cooked (buffer))
 
-(mm-define-method entity-cooked-p ((entity cooked)) t)
+(mm-define-method entity-cooked-p ((_entity cooked)) t)
 
 (mm-define-method write-entity-content ((entity cooked) filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (let ((encoding (or (mime-entity-encoding entity) "7bit")))
       (if (member encoding '("7bit" "8bit" "binary"))
 	  (write-region (mime-buffer-entity-body-start-internal entity)
@@ -40,24 +39,19 @@
 	(mime-write-decoded-region
 	 (mime-buffer-entity-body-start-internal entity)
 	 (mime-buffer-entity-body-end-internal entity)
-	 filename encoding)
-	))))
+	 filename encoding)))))
 
 (mm-define-method write-entity ((entity cooked) filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (write-region (mime-buffer-entity-header-start-internal entity)
 		  (mime-buffer-entity-body-end-internal entity)
-		  filename)
-    ))
+		  filename)))
 
 (mm-define-method write-entity-body ((entity cooked) filename)
-  (save-excursion
-    (set-buffer (mime-buffer-entity-buffer-internal entity))
+  (with-current-buffer (mime-buffer-entity-buffer-internal entity)
     (write-region (mime-buffer-entity-body-start-internal entity)
 		  (mime-buffer-entity-body-end-internal entity)
-		  filename)
-    ))
+		  filename)))
 
 (luna-define-method mime-insert-header ((entity mime-cooked-entity)
 					&optional invisible-fields
@@ -66,8 +60,7 @@
     (funcall (car (luna-class-find-functions
 		   (luna-find-class 'mime-buffer-entity)
 		   'mime-insert-header))
-	     entity invisible-fields visible-fields)
-    ))
+	     entity invisible-fields visible-fields)))
 
 (mm-define-method insert-text-content ((entity cooked))
   (let ((str (mime-entity-content entity)))
@@ -80,8 +73,7 @@
 					(mime-entity-content-type entity)
 					"charset")
 				       default-mime-charset)
-				   'CRLF)
-       ))))
+				   'CRLF)))))
 
 
 ;;; @ end
