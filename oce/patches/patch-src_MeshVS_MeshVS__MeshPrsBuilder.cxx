$NetBSD: patch-src_MeshVS_MeshVS__MeshPrsBuilder.cxx,v 1.1 2015/06/25 12:41:09 fhajny Exp $

SunOS needs alloca.h.
--- src/MeshVS/MeshVS_MeshPrsBuilder.cxx.orig	2015-03-08 22:19:42.000000000 +0000
+++ src/MeshVS/MeshVS_MeshPrsBuilder.cxx
@@ -56,6 +56,10 @@
 #include <NCollection_Map.hxx>
 #include <NCollection_Vector.hxx>
 
+#if defined(__sun)
+#include <alloca.h>
+#endif
+
 //================================================================
 // Function : Constructor MeshVS_MeshPrsBuilder
 // Purpose  :
