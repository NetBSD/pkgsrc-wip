$NetBSD$

Fix copying of an empty bytevector when start and end arguments
are omitted.

Make let-values be the same as let*-values, to work around 

 https://github.com/justinethier/cyclone/issues/504

--- scheme/base.sld.orig	2026-07-27 21:18:39.260568143 +0000
+++ scheme/base.sld
@@ -972,7 +972,9 @@
       (letrec ((len (bytevector-length bv))
                (start (if (> (length opts) 0) (car opts) 0))
                (end (if (> (length opts) 1) (cadr opts) len)))
-        (Cyc-bytevector-copy bv start end)))
+        (if (and (equal? len 0) (equal? (length opts) 0))
+          (make-bytevector 0)
+          (Cyc-bytevector-copy bv start end))))
     (define (bytevector-copy! to at from . o)
       (let* ((start (if (pair? o) (car o) 0))
              (end (if (and (pair? o) (pair? (cdr o)))
@@ -1877,7 +1879,7 @@
      (let-values ("step") () () expr () params rest . body))
     ))
 
-(define-syntax
+#;(define-syntax
   let-values
   (syntax-rules
     ()
@@ -1945,6 +1947,13 @@
        (lambda (arg ... . x)
          (let-values "bind" bindings (tmp ... (a x)) body))))))
 
+(define-syntax
+  let-values
+  (syntax-rules
+    ()
+    ((let-values (binding ...) body0 body1 ...)
+     (let*-values (binding ...) body0 body1 ...))))
+
 (define-syntax guard
   (syntax-rules ()
     ((guard (var clause ...) e1 e2 ...)
