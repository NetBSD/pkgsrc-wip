$NetBSD: patch-include_h235.h,v 1.1 2013/07/17 12:52:45 obache Exp $

--- include/h235.h.orig	2007-08-06 20:50:49.000000000 +0000
+++ include/h235.h
@@ -88,7 +88,7 @@ class H235_Password : public PASN_BMPStr
 
     H235_Password & operator=(const char * v);
     H235_Password & operator=(const PString & v);
-    H235_Password & operator=(const PWORDArray & v);
+    H235_Password & operator=(const PWCharArray & v);
     H235_Password & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
@@ -108,7 +108,7 @@ class H235_Identifier : public PASN_BMPS
 
     H235_Identifier & operator=(const char * v);
     H235_Identifier & operator=(const PString & v);
-    H235_Identifier & operator=(const PWORDArray & v);
+    H235_Identifier & operator=(const PWCharArray & v);
     H235_Identifier & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
