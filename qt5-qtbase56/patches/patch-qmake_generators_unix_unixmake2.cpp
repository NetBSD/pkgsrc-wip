$NetBSD: patch-qmake_generators_unix_unixmake2.cpp,v 1.2 2015/10/26 19:03:59 adam Exp $

* Libtoolized
* add back compile_libtool support that was ripped out in qt5.6

--- qmake/generators/unix/unixmake2.cpp.orig	2016-12-01 08:17:04.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -50,6 +50,10 @@ UnixMakefileGenerator::writePrlFile(QTex
     MakefileGenerator::writePrlFile(t);
     // libtool support
     if(project->isActiveConfig("create_libtool") && project->first("TEMPLATE") == "lib") { //write .la
+        if(project->isActiveConfig("compile_libtool"))
+            warn_msg(WarnLogic, "create_libtool specified with compile_libtool can lead to conflicting .la\n"
+                     "formats, create_libtool has been disabled\n");
+	else
         writeLibtoolFile();
     }
     // pkg-config support
@@ -169,12 +173,12 @@ UnixMakefileGenerator::writeMakeParts(QT
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
@@ -198,13 +202,15 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << endl;
-        t << "LIBS          = $(SUBLIBS) " << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
+        t << "LFLAGS       += " << var("QMAKE_LFLAGS") << endl;
+        t << "LIBS         += $(SUBLIBS) " << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS_PRIVATE").join(' ') << endl;
     }
 
     t << "AR            = " << var("QMAKE_AR") << endl;
     t << "RANLIB        = " << var("QMAKE_RANLIB") << endl;
+    if(project->isActiveConfig("compile_libtool"))
+	t << "LIBTOOL       = " << var("QMAKE_LIBTOOL") << endl;
     t << "SED           = " << var("QMAKE_STREAM_EDITOR") << endl;
     t << "STRIP         = " << var("QMAKE_STRIP") << endl;
 
@@ -265,6 +271,8 @@ UnixMakefileGenerator::writeMakeParts(QT
     if (destd.endsWith('\\'))
         destd += '\\';
     t << "DESTDIR       = " << destd << endl;
+    if(project->isActiveConfig("compile_libtool"))
+	t << "TARGETL       = " << fileVar("TARGET_la") << endl;
     t << "TARGET        = " << fileVar("TARGET") << endl; // ### mixed use!
     if(project->isActiveConfig("plugin")) {
         t << "TARGETD       = " << fileVar("TARGET") << endl;
@@ -273,6 +281,8 @@ UnixMakefileGenerator::writeMakeParts(QT
         if(!project->isEmpty("QMAKE_BUNDLE")) {
             t << "TARGETD       = " << fileVar("TARGET_x.y") << endl;
             t << "TARGET0       = " << fileVar("TARGET_") << endl;
+        } else if(project->isActiveConfig("compile_libtool")) {
+            t << "TARGETD       = " << var("TARGET_la") << endl;
         } else if (!project->isActiveConfig("unversioned_libname")) {
             t << "TARGET0       = " << fileVar("TARGET_") << endl;
             if (project->isEmpty("QMAKE_HPUX_SHLIB")) {
@@ -578,7 +588,9 @@ UnixMakefileGenerator::writeMakeParts(QT
         if(!project->isEmpty("QMAKE_PRE_LINK"))
             t << "\n\t" << var("QMAKE_PRE_LINK");
 
-        if (project->isActiveConfig("plugin")) {
+	if(project->isActiveConfig("compile_libtool")) {
+	    t << "\n\t" << var("QMAKE_LINK_SHLIB_CMD");
+        } else if (project->isActiveConfig("plugin")) {
             t << "\n\t"
               << "-$(DEL_FILE) $(TARGET)\n\t"
               << var("QMAKE_LINK_SHLIB_CMD");
@@ -722,7 +734,7 @@ UnixMakefileGenerator::writeMakeParts(QT
     writeMakeQmake(t);
     if(project->isEmpty("QMAKE_FAILED_REQUIREMENTS") && !project->isActiveConfig("no_autoqmake")) {
         QStringList meta_files;
-        if (project->isActiveConfig("create_libtool") && project->first("TEMPLATE") == "lib") { //libtool
+        if (project->isActiveConfig("create_libtool") && project->first("TEMPLATE") == "lib" && !project->isActiveConfig("compile_libtool")) { //libtool
             meta_files += libtoolFileName();
         }
         if(project->isActiveConfig("create_pc") && project->first("TEMPLATE") == "lib") { //pkg-config
@@ -957,6 +969,9 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     t << "clean:" << clean_targets << "\n\t";
     if(!project->isEmpty("OBJECTS")) {
+        if(project->isActiveConfig("compile_libtool"))
+            t << "-$(LIBTOOL) --mode=clean $(DEL_FILE) $(OBJECTS)\n\t";
+        else
         t << "-$(DEL_FILE) $(OBJECTS)\n\t";
     }
     if(doPrecompiledHeaders() && !project->isEmpty("PRECOMPILED_HEADER")) {
@@ -1013,6 +1028,8 @@ UnixMakefileGenerator::writeMakeParts(QT
     if(!project->isEmpty("QMAKE_BUNDLE")) {
         QString bundlePath = escapeFilePath(destdir + project->first("QMAKE_BUNDLE"));
         t << "\t-$(DEL_FILE) -r " << bundlePath << endl;
+    } else if(project->isActiveConfig("compile_libtool")) {
+        t << "\t-$(LIBTOOL) --mode=clean $(DEL_FILE) $(TARGET)\n";
     } else if (project->isActiveConfig("staticlib") || project->isActiveConfig("plugin")) {
         t << "\t-$(DEL_FILE) " << escapeFilePath(destdir) << "$(TARGET) \n";
     } else if (project->values("QMAKE_APP_FLAG").isEmpty()) {
@@ -1139,18 +1156,26 @@ void UnixMakefileGenerator::init2()
     } else if (project->isActiveConfig("staticlib")) {
         project->values("TARGET").first().prepend(project->first("QMAKE_PREFIX_STATICLIB"));
         project->values("TARGET").first() += "." + project->first("QMAKE_EXTENSION_STATICLIB");
-        if(project->values("QMAKE_AR_CMD").isEmpty())
+        if(project->values("QMAKE_AR_CMD").isEmpty()) {
+          if(project->isActiveConfig("compile_libtool"))
+            project->variables()["QMAKE_AR_CMD"].append("$(CXX) -o $(TARGET) $(OBJECTS) $(OBJMOC)");
+          else
             project->values("QMAKE_AR_CMD").append("$(AR) $(DESTDIR)$(TARGET) $(OBJECTS)");
+        }
     } else {
         project->values("TARGETA").append(project->first("DESTDIR") + project->first("QMAKE_PREFIX_STATICLIB")
                 + project->first("TARGET") + "." + project->first("QMAKE_EXTENSION_STATICLIB"));
+        if(project->isActiveConfig("compile_libtool"))
+            project->values("TARGET_la") = ProStringList(project->first("DESTDIR") + "lib" + project->first("TARGET") + Option::libtool_ext);
 
         ProStringList &ar_cmd = project->values("QMAKE_AR_CMD");
         if (!ar_cmd.isEmpty())
             ar_cmd[0] = ar_cmd.at(0).toQString().replace(QLatin1String("(TARGET)"), QLatin1String("(TARGETA)"));
         else
             ar_cmd.append("$(AR) $(TARGETA) $(OBJECTS)");
-        if (!project->isEmpty("QMAKE_BUNDLE")) {
+        if(project->isActiveConfig("compile_libtool")) {
+            project->values("TARGET") = project->values("TARGET_la");
+        } else if (!project->isEmpty("QMAKE_BUNDLE")) {
             ProString bundle_loc = project->first("QMAKE_BUNDLE_LOCATION");
             if(!bundle_loc.isEmpty() && !bundle_loc.startsWith("/"))
                 bundle_loc.prepend("/");
@@ -1304,7 +1329,7 @@ void UnixMakefileGenerator::init2()
             project->values("QMAKE_CFLAGS") += project->values("QMAKE_CFLAGS_PLUGIN");
             project->values("QMAKE_CXXFLAGS") += project->values("QMAKE_CXXFLAGS_PLUGIN");
             project->values("QMAKE_LFLAGS") += project->values("QMAKE_LFLAGS_PLUGIN");
-            if (project->isActiveConfig("plugin_with_soname"))
+            if (project->isActiveConfig("plugin_with_soname") && !project->isActiveConfig("compile_libtool"))
                 project->values("QMAKE_LFLAGS") += project->values("QMAKE_LFLAGS_SONAME");
         } else {
             project->values("QMAKE_LFLAGS") += project->values("QMAKE_LFLAGS_SHLIB");
@@ -1323,6 +1348,7 @@ void UnixMakefileGenerator::init2()
                                                                 project->first("VER_MIN") + "." +
                                                                 project->first("VER_PAT"));
             }
+            if(!project->isActiveConfig("compile_libtool"))
             project->values("QMAKE_LFLAGS") += project->values("QMAKE_LFLAGS_SONAME");
         }
     }
