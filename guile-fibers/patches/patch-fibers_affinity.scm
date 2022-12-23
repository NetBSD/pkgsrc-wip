$NetBSD$

--- fibers/affinity.scm.orig	2022-12-22 20:10:48.000000000 +0000
+++ fibers/affinity.scm
@@ -21,10 +21,27 @@
 ;;; library.
 
 (define-module (fibers affinity)
-  #:use-module (system foreign)
-  #:use-module (fibers config)
+  #:use-module (ice-9 threads)
   #:export (getaffinity* setaffinity*))
 
+;;
+;; Some platforms don't implement (getaffinity) or (setaffinity).
+;;
+;; For example, it seems it is not possible to link a thread to a specific core
+;; on macOS. See: https://developer.apple.com/forums/thread/44002.
+;;
+;; So for now getaffinity/setaffinity are no-ops on those paltforms.
+;;
+
 ;; getaffinity/setaffinity should be defined in Guile
-(define getaffinity* (if (defined? 'getaffinity) getaffinity))
-(define setaffinity* (if (defined? 'setaffinity) setaffinity))
+(define getaffinity*
+  (cond
+   ((defined? 'getaffinity) getaffinity)
+   (else
+    (lambda (pid)
+      (make-bitvector (current-processor-count) 1)))))
+
+(define setaffinity*
+  (cond
+   ((defined? 'setaffinity) setaffinity)
+   (else (lambda (pid affinity) *unspecified*))))
