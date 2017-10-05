$NetBSD$

--- lib/scudo/scudo_tsd_exclusive.inc.orig	2017-10-02 13:17:02.000000000 +0000
+++ lib/scudo/scudo_tsd_exclusive.inc
@@ -22,6 +22,7 @@ enum ThreadState : u8 {
   ThreadInitialized,
   ThreadTornDown,
 };
+
 __attribute__((tls_model("initial-exec")))
 extern THREADLOCAL ThreadState ScudoThreadState;
 __attribute__((tls_model("initial-exec")))
