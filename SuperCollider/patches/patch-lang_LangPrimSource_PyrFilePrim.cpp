$NetBSD: patch-lang_LangPrimSource_PyrFilePrim.cpp,v 1.1 2014/09/06 22:22:36 thomasklausner Exp $

Use proper interface.

--- lang/LangPrimSource/PyrFilePrim.cpp.orig	2013-11-27 12:54:02.000000000 +0000
+++ lang/LangPrimSource/PyrFilePrim.cpp
@@ -323,23 +323,15 @@ int prFilePos(struct VMGlobals *g, int n
 	PyrSlot *a;
 	PyrFile *pfile;
 	FILE *file;
-	fpos_t pos;
-	int length;
+	off_t length;
 
 	a = g->sp;
 	pfile = (PyrFile*)slotRawObject(a);
 	file = (FILE*)slotRawPtr(&pfile->fileptr);
 	if (file == NULL) return errFailed;
-	if (fgetpos(file, &pos)) return errFailed;
-
-#ifdef __linux__
-	// sk: hack alert!
-	length = pos.__pos;
-#else
-	length = pos;
-#endif
+	if ((length=ftell(file)) == -1) return errFailed;
 
-	SetInt(a, length);
+	SetInt(a, (int)length);
 	return errNone;
 }
 
