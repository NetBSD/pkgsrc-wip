$NetBSD: patch-plugins_mht_xp_ie__imp__MHT.cpp,v 1.1 2014/12/29 20:31:15 nros Exp $
* constructImporters first argument is &var so pBB must dereferenced
* Refer to the importFile method that takes const char *.
--- plugins/mht/xp/ie_imp_MHT.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/mht/xp/ie_imp_MHT.cpp
@@ -292,7 +292,7 @@ FG_Graphic * IE_Imp_MHT::importImage (co
 		}
 
 	IE_ImpGraphic * pieg = 0;
-	if (IE_ImpGraphic::constructImporter (pBB, IEGFT_Unknown, &pieg) != UT_OK)
+	if (IE_ImpGraphic::constructImporter (*pBB, IEGFT_Unknown, &pieg) != UT_OK)
 		{
 			UT_DEBUGMSG(("unable to construct image importer!\n"));
 			return 0;
@@ -323,7 +323,7 @@ UT_Error IE_Imp_MHT::importXHTML (const 
 
 	setReader (&wrapper);
 
-	return IE_Imp_XHTML::importFile (szFilename);
+	return IE_Imp_MHT::importFile (szFilename);
 }
 
 UT_Error IE_Imp_MHT::importHTML4 (const char * szFilename)
@@ -337,7 +337,7 @@ UT_Error IE_Imp_MHT::importHTML4 (const 
 	TidyReader wrapper(buffer,length);
 	setReader (&wrapper);
 
-	e = IE_Imp_XHTML::importFile (szFilename);
+	e = IE_Imp_MHT::importFile (szFilename);
 
 	setReader (0);
 #endif
@@ -351,7 +351,7 @@ UT_Error IE_Imp_MHT::importHTML4 (const 
 	UT_HTML parser;
 	setParser (&parser);
 
-	e = IE_Imp_XHTML::importFile (szFilename);
+	e = IE_Imp_MHT::importFile (szFilename);
 
 	setParser (0);
 	setReader (0);
