$NetBSD$

Adjust the test output, the generated symbol name is different
due to pkgsrc patches.

--- tests/macro-hygiene.scm.orig	2024-02-28 22:52:36.860745787 +0000
+++ tests/macro-hygiene.scm
@@ -138,7 +138,7 @@
 ;; ;;; Examples from the source to R5RS pitfall 3.3
 ;; ;;;; (assert/equal
   (test
-   '(1 2 3 a$1385)
+   '(1 2 3 a$1703)
    ;'(1 2 3 a)
     (let ((a 1))
        (letrec-syntax
