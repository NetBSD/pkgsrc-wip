$NetBSD$

--- src/VBox/Main/include/ovfreader.h.orig	2016-03-04 19:29:37.000000000 +0000
+++ src/VBox/Main/include/ovfreader.h
@@ -174,7 +174,8 @@ enum CIMOSType_T
     CIMOSType_CIMOS_CentOS_64 = 107,
     CIMOSType_CIMOS_OracleEnterpriseLinux = 108,
     CIMOSType_CIMOS_OracleEnterpriseLinux_64 = 109,
-    CIMOSType_CIMOS_eComStation = 110
+    CIMOSType_CIMOS_eComStation = 110,
+    CIMOSType_CIMOS_NetBSD_64  = 78,
     // no new types added with CIM 2.26.0
 };
 
@@ -655,4 +656,3 @@ private:
 } // end namespace ovf
 
 #endif // !____H_OVFREADER
-
