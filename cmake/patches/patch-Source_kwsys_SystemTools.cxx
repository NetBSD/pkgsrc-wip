$NetBSD: patch-Source_kwsys_SystemTools.cxx,v 1.1 2014/09/27 06:05:02 makoto Exp $

* SCO OpenServer 5.0.7/3.2's command has 711 permission.

--- Source/kwsys/SystemTools.cxx.orig	2014-09-11 22:24:01.000000000 +0900
+++ Source/kwsys/SystemTools.cxx	2014-09-23 11:56:10.000000000 +0900
@@ -1081,7 +1081,12 @@ bool SystemTools::FileExists(const char*
   return (GetFileAttributesW(Encoding::ToWide(filename).c_str())
           != INVALID_FILE_ATTRIBUTES);
 #else
+// SCO OpenServer 5.0.7/3.2's command has 711 permission.
+#  if defined(_SCO_DS)
+  return access(filename, F_OK) == 0;
+#  else
   return access(filename, R_OK) == 0;
+#  endif
 #endif
 }
 
