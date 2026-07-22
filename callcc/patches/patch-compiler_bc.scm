$NetBSD$

Pass the pkg-config flags to the compiler. The flags are stored in
"bc-libs.scm" at build time.

--- compiler/bc.scm.orig	2026-07-22 19:24:59.899424994 +0000
+++ compiler/bc.scm
@@ -1,3 +1,5 @@
+(include "bc-libs.scm")
+
 (define next-id (make-counter 0))
 
 (define-record-type fun (%make-fun code name last-label args thunk debug-id debug-loc-id) fun?
@@ -589,7 +591,7 @@ attributes #0 = { returns_twice}
        (display line) (newline)))
 
 (define (get-link-command output output-file opts)
-  (let ((link (format "clang ~a -g -o ~a ~a ~alibcallcc.a -lm -lgmp -lutf8proc"
-		      opts output-file output (get-compile-path))))
+  (let ((link (format "clang ~a -g -o ~a ~a ~alibcallcc.a -lm ~a"
+		      opts output-file output (get-compile-path) callcc-link-libs)))
     (display (format "Running link: ~a\n" link) (current-error-port))
     link))
