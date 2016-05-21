$NetBSD: patch-qmake_generators_unix_unixmake2.cpp,v 1.2 2015/10/26 19:03:59 adam Exp $

* Libtoolized

--- qmake/generators/unix/unixmake2.cpp.orig	2016-05-20 00:28:32.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -173,12 +173,12 @@ UnixMakefileGenerator::writeMakeParts(QT
     t << "####### Compiler, tools and options\n\n";
     t << "CC            = " << var("QMAKE_CC") << endl;
     t << "CXX           = " << var("QMAKE_CXX") << endl;
-    t << "DEFINES       = "
+    t << "DEFINES      += "
       << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
       << varGlue("DEFINES","-D"," -D","") << endl;
-    t << "CFLAGS        = " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
-    t << "CXXFLAGS      = " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
-    t << "INCPATH       =";
+    t << "CFLAGS       += " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
+    t << "CXXFLAGS     += " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
+    t << "INCPATH      +=";
     {
         QString isystem = var("QMAKE_CFLAGS_ISYSTEM");
         const ProStringList &incs = project->values("INCLUDEPATH");
@@ -202,8 +202,8 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << endl;
-        t << "LIBS          = $(SUBLIBS) " << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
+        t << "LFLAGS       += " << var("QMAKE_LFLAGS") << endl;
+        t << "LIBS         += $(SUBLIBS) " << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS_PRIVATE").join(' ') << endl;
     }
 
@@ -277,6 +277,8 @@ UnixMakefileGenerator::writeMakeParts(QT
         if(!project->isEmpty("QMAKE_BUNDLE")) {
             t << "TARGETD       = " << fileVar("TARGET_x.y") << endl;
             t << "TARGET0       = " << fileVar("TARGET_") << endl;
+        } else if(project->isActiveConfig("compile_libtool")) {
+            t << "TARGETD       = " << var("TARGET_la") << endl;
         } else if (!project->isActiveConfig("unversioned_libname")) {
             t << "TARGET0       = " << fileVar("TARGET_") << endl;
             if (project->isEmpty("QMAKE_HPUX_SHLIB")) {
