$NetBSD$

Make let-values be the same as let*-values, to work around 

 https://github.com/justinethier/cyclone/issues/504

--- scheme/base.sld.orig	2022-08-25 21:12:33.000000000 +0000
+++ scheme/base.sld
@@ -1877,7 +1877,7 @@
      (let-values ("step") () () expr () params rest . body))
     ))
 
-(define-syntax
+#;(define-syntax
   let-values
   (syntax-rules
     ()
@@ -1945,6 +1945,13 @@
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
