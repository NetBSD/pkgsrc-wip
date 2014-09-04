$NetBSD: patch-plugins_imfile_imfile.c,v 1.1 2014/09/04 09:33:08 fhajny Exp $

Avoid unresolved symbol on inotify-less platforms.

--- plugins/imfile/imfile.c.orig	2014-06-02 09:53:18.000000000 +0000
+++ plugins/imfile/imfile.c
@@ -1348,10 +1348,14 @@ BEGINrunInput
 CODESTARTrunInput
 	DBGPRINTF("imfile: working in %s mode\n", 
 		 (runModConf->opMode == OPMODE_POLLING) ? "polling" : "inotify");
+#if HAVE_INOTIFY_INIT
 	if(runModConf->opMode == OPMODE_POLLING)
 		iRet = doPolling();
 	else
 		iRet = do_inotify();
+#else
+	iRet = doPolling();
+#endif
 
 	DBGPRINTF("imfile: terminating upon request of rsyslog core\n");
 	RETiRet;	/* use it to make sure the housekeeping is done! */
