$NetBSD$

Allow starting gnucash in the background.
python's readline module causes a SIGTTOU to be sent and if this
is not handled (even by ignoring it), it stops the process.

--- gnucash/gnucash-bin.c.orig	2017-10-28 21:23:58.000000000 +0000
+++ gnucash/gnucash-bin.c
@@ -22,6 +22,7 @@
  */
 #include <config.h>
 
+#include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -608,6 +609,8 @@ inner_main (void *closure, int argc, cha
     SCM main_mod;
     char* fn;
 
+    signal(SIGTTOU, SIG_IGN);
+
     scm_c_eval_string("(debug-set! stack 200000)");
 
     main_mod = scm_c_resolve_module("gnucash main");
