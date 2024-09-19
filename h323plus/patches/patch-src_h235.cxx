$NetBSD: patch-src_h235.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/h235.cxx.orig	2007-08-06 20:51:05.000000000 +0000
+++ src/h235.cxx
@@ -169,7 +169,7 @@ H235_Password & H235_Password::operator=
 }
 
 
-H235_Password & H235_Password::operator=(const PWORDArray & v)
+H235_Password & H235_Password::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
@@ -217,7 +217,7 @@ H235_Identifier & H235_Identifier::opera
 }
 
 
-H235_Identifier & H235_Identifier::operator=(const PWORDArray & v)
+H235_Identifier & H235_Identifier::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
