$NetBSD: patch-plugins_imsolaris_imsolaris.c,v 1.1 2012/03/05 13:19:09 fhajny Exp $

Patch from http://lists.adiscon.net/pipermail/rsyslog/2011-October/013850.html
--- plugins/imsolaris/imsolaris.c.orig	2012-01-09 14:05:17.000000000 +0000
+++ plugins/imsolaris/imsolaris.c
@@ -392,9 +392,9 @@ CODEmodInit_QueryRegCFSLineHdlr
 
 	/* register config file handlers */
 	CHKiRet(omsdRegCFSLineHdlr((uchar *)"resetconfigvariables", 1, eCmdHdlrCustomHandler,
-		resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID));
+		resetConfigVariables, NULL, STD_LOADABLE_MODULE_ID, eConfObjAction));
         CHKiRet(omsdRegCFSLineHdlr((uchar *)"imsolarislogsocketname", 0, eCmdHdlrGetWord,
-                NULL, &LogName, STD_LOADABLE_MODULE_ID));
+                NULL, &LogName, STD_LOADABLE_MODULE_ID, eConfObjAction));
 ENDmodInit
 /* vim:set ai:
  */
