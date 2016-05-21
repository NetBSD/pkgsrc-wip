$NetBSD: patch-qmake_generators_makefile.cpp,v 1.2 2015/10/26 19:03:59 adam Exp $

* Libtoolized

--- qmake/generators/makefile.cpp.orig	2016-05-20 00:28:32.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3290,7 +3290,7 @@ MakefileGenerator::writePkgConfigFile()
         pkgConfiglibName = bundle.toQString();
     } else {
         if (!project->values("QMAKE_DEFAULT_LIBDIRS").contains(libDir))
-            t << "-L${libdir} ";
+            t << "-Wl,-R${libdir} -L${libdir} ";
         pkgConfiglibName = "-l" + project->first("QMAKE_ORIG_TARGET");
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
