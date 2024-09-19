$NetBSD: patch-src_h450_h4508.cxx,v 1.1 2013/07/17 12:52:45 obache Exp $

--- src/h450/h4508.cxx.orig	2007-08-06 20:51:39.000000000 +0000
+++ src/h450/h4508.cxx
@@ -418,7 +418,7 @@ H4508_ExtendedName & H4508_ExtendedName:
 }
 
 
-H4508_ExtendedName & H4508_ExtendedName::operator=(const PWORDArray & v)
+H4508_ExtendedName & H4508_ExtendedName::operator=(const PWCharArray & v)
 {
   SetValue(v);
   return *this;
