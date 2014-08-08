$NetBSD: patch-plugins_mmjsonparse_mmjsonparse.c,v 1.1 2014/08/08 08:03:08 fhajny Exp $

Fix for json-c>0.11.
--- plugins/mmjsonparse/mmjsonparse.c.orig	2014-03-25 20:37:43.000000000 +0000
+++ plugins/mmjsonparse/mmjsonparse.c
@@ -146,7 +146,7 @@ processJSON(instanceData *pData, msg_t *
 
 			err = pData->tokener->err;
 			if(err != json_tokener_continue)
-				errMsg = json_tokener_errors[err];
+				errMsg = json_tokener_error_desc(err);
 			else
 				errMsg = "Unterminated input";
 		} else if((size_t)pData->tokener->char_offset < lenBuf)
