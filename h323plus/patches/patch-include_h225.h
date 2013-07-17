$NetBSD: patch-include_h225.h,v 1.1 2013/07/17 12:52:45 obache Exp $

--- include/h225.h.orig	2007-08-06 20:50:48.000000000 +0000
+++ include/h225.h
@@ -1184,7 +1184,7 @@ class H225_GatekeeperIdentifier : public
 
     H225_GatekeeperIdentifier & operator=(const char * v);
     H225_GatekeeperIdentifier & operator=(const PString & v);
-    H225_GatekeeperIdentifier & operator=(const PWORDArray & v);
+    H225_GatekeeperIdentifier & operator=(const PWCharArray & v);
     H225_GatekeeperIdentifier & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
@@ -1240,7 +1240,7 @@ class H225_EndpointIdentifier : public P
 
     H225_EndpointIdentifier & operator=(const char * v);
     H225_EndpointIdentifier & operator=(const PString & v);
-    H225_EndpointIdentifier & operator=(const PWORDArray & v);
+    H225_EndpointIdentifier & operator=(const PWCharArray & v);
     H225_EndpointIdentifier & operator=(const PASN_BMPString & v);
     PObject * Clone() const;
 };
