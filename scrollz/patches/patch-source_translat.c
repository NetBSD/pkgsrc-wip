$NetBSD: patch-source_translat.c,v 1.1 2012/11/13 12:53:54 othyro Exp $

Fixes incompatible pointer type error.

--- source/translat.c.orig	2011-04-29 08:21:18.000000000 +0000
+++ source/translat.c
@@ -379,7 +379,7 @@ displayable_unival(unsigned unival, icon
 		
 		/*	*outptr = '\0'; */
 		retval = iconv(conv_out,
-		               (iconv_const char**)&utfptr, &utfspace,
+		               (const char**)&utfptr, &utfspace,
 		               (char **)&outptr, &outspace);
 
 		/*
@@ -598,7 +598,7 @@ decode_mb(ptr, dest, data)
 			cptr = (char *)ptr;
 			cutfptr = (char *)utfptr;
 			retval = iconv(data->conv_in,
-			               (iconv_const char**)&ptr, &is,
+			               (const char**)&ptr, &is,
 			               (char **)&utfptr, &utfspace);
 		
 			data->input_bytes  += gave-is;
