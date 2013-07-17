$NetBSD: patch-include_gccpdu.h,v 1.1 2013/07/17 12:52:44 obache Exp $

--- include/gccpdu.h.orig	2007-08-06 20:50:48.000000000 +0000
+++ include/gccpdu.h
@@ -271,7 +271,7 @@ class GCC_TextString : public PASN_BMPSt
 
     GCC_TextString & operator=(const char * v);
     GCC_TextString & operator=(const PString & v);
-    GCC_TextString & operator=(const PWORDArray & v);
+    GCC_TextString & operator=(const PWCharArray & v);
     GCC_TextString & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
@@ -291,7 +291,7 @@ class GCC_SimpleTextString : public PASN
 
     GCC_SimpleTextString & operator=(const char * v);
     GCC_SimpleTextString & operator=(const PString & v);
-    GCC_SimpleTextString & operator=(const PWORDArray & v);
+    GCC_SimpleTextString & operator=(const PWCharArray & v);
     GCC_SimpleTextString & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
@@ -365,7 +365,7 @@ class GCC_ExtraDialingString : public PA
 
     GCC_ExtraDialingString & operator=(const char * v);
     GCC_ExtraDialingString & operator=(const PString & v);
-    GCC_ExtraDialingString & operator=(const PWORDArray & v);
+    GCC_ExtraDialingString & operator=(const PWCharArray & v);
     GCC_ExtraDialingString & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
