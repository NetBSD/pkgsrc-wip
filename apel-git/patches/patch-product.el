$NetBSD: patch-product.el,v 1.1 2013/10/03 11:17:02 makoto Exp $

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

--- product.el.orig	2013-10-03 19:21:38.000000000 +0900
+++ product.el	2013-10-03 19:33:10.000000000 +0900
@@ -232,21 +232,21 @@ PRODUCT-DEF is a definition of the produ
 	 (product-version (product-version product))
 	 (product-code-name (product-code-name product))
 	 (product-version-string (product-version-string product)))
-    (` (progn
-	 (, product-def)
-	 (put (, feature) 'product
-	      (let ((product (product-find-by-name (, product-name))))
-		(product-run-checkers product '(, product-version))
-		(and (, product-family)
-		     (product-add-to-family (, product-family)
-					    (, product-name)))
-		(product-add-feature product (, feature))
-		(if (equal '(, product-version) (product-version product))
-		    product
-		  (vector (, product-name) (, product-family)
-			  '(, product-version) (, product-code-name)
-			  nil nil nil (, product-version-string)))))
-	 (, feature-def)))))
+    `(progn
+       ,product-def
+       (put ,feature 'product
+            (let ((product (product-find-by-name ,product-name)))
+              (product-run-checkers product ',product-version)
+              (and ,product-family
+                   (product-add-to-family ,product-family
+                                          ,product-name))
+              (product-add-feature product ,feature)
+              (if (equal ',product-version (product-version product))
+                  product
+                (vector ,product-name ,product-family
+                        ',product-version ,product-code-name
+                        nil nil nil ,product-version-string))))
+       ,feature-def)))
 
 (defun product-version-as-string (product)
   "Return version number of product as a string.
