$NetBSD$

Limit the defined macros to only those required by R7RS (intersection with (Cyc-global-vars)).

--- cyclone.scm.orig	2024-02-14 02:31:23.000000000 +0000
+++ cyclone.scm
@@ -203,10 +203,12 @@
       ;; in final compiled program
       ;(set! input-program (add-libs input-program))
     
+      (define *required-macros* '(include include-ci and or let let* letrec begin cond-expand cond case when unless do quasiquote syntax-error parameterize with-handler syntax-rules letrec* let*-values let-values guard define-record-type define-values))
+
       ;; Load macros for expansion phase
       (let ((macros (filter 
                       (lambda (v) 
-                        (Cyc-macro? (Cyc-get-cvar (cdr v))))
+                        (and (member (car v) *required-macros*) (Cyc-macro? (Cyc-get-cvar (cdr v)))))
                       (Cyc-global-vars))))
         (set! *defined-macros*
               (append
