$NetBSD: patch-include_h501.h,v 1.1 2013/07/17 12:52:45 obache Exp $

--- include/h501.h.orig	2007-08-06 20:50:49.000000000 +0000
+++ include/h501.h
@@ -1075,7 +1075,7 @@ class H501_ElementIdentifier : public PA
 
     H501_ElementIdentifier & operator=(const char * v);
     H501_ElementIdentifier & operator=(const PString & v);
-    H501_ElementIdentifier & operator=(const PWORDArray & v);
+    H501_ElementIdentifier & operator=(const PWCharArray & v);
     H501_ElementIdentifier & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
