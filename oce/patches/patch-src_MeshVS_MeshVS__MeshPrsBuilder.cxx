$NetBSD: patch-src_MeshVS_MeshVS__MeshPrsBuilder.cxx,v 1.1 2015/06/25 12:41:09 fhajny Exp $

SunOS needs alloca.h.
--- src/MeshVS/MeshVS_MeshPrsBuilder.cxx.orig	2016-01-02 05:11:52.000000000 +0000
+++ src/MeshVS/MeshVS_MeshPrsBuilder.cxx
@@ -61,6 +61,10 @@
   #define alloca __builtin_alloca 
   #endif
 #endif
+
+#if defined(__sun)
+#include <alloca.h>
+#endif
 //================================================================
 // Function : Constructor MeshVS_MeshPrsBuilder
 // Purpose  :
