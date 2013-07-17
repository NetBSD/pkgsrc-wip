$NetBSD: patch-src_gccpdu.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/gccpdu.cxx.orig	2007-08-06 20:51:04.000000000 +0000
+++ src/gccpdu.cxx
@@ -556,7 +556,7 @@ GCC_TextString & GCC_TextString::operato
 }
 
 
-GCC_TextString & GCC_TextString::operator=(const PWORDArray & v)
+GCC_TextString & GCC_TextString::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
@@ -605,7 +605,7 @@ GCC_SimpleTextString & GCC_SimpleTextStr
 }
 
 
-GCC_SimpleTextString & GCC_SimpleTextString::operator=(const PWORDArray & v)
+GCC_SimpleTextString & GCC_SimpleTextString::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
@@ -759,7 +759,7 @@ GCC_ExtraDialingString & GCC_ExtraDialin
 }
 
 
-GCC_ExtraDialingString & GCC_ExtraDialingString::operator=(const PWORDArray & v)
+GCC_ExtraDialingString & GCC_ExtraDialingString::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
