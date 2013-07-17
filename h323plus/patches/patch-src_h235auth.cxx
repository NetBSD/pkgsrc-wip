$NetBSD: patch-src_h235auth.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/h235auth.cxx.orig	2007-08-06 20:51:05.000000000 +0000
+++ src/h235auth.cxx
@@ -605,9 +605,9 @@ const char * H235AuthSimpleMD5::GetName(
 }
 
 
-static PWORDArray GetUCS2plusNULL(const PString & str)
+static PWCharArray GetUCS2plusNULL(const PString & str)
 {
-  PWORDArray ucs2 = str.AsUCS2();
+  PWCharArray ucs2 = str.AsUCS2();
   PINDEX len = ucs2.GetSize();
   if (len > 0 && ucs2[len-1] != 0)
     ucs2.SetSize(len+1);
