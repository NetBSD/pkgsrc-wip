$NetBSD: patch-qmake_generators_unix_unixmake.cpp,v 1.3 2015/10/26 19:03:59 adam Exp $

* fix install target so that destdir is added when installing QMAKE_TARGET

--- qmake/generators/unix/unixmake.cpp.orig	2016-05-20 00:28:32.000000000 +0000
+++ qmake/generators/unix/unixmake.cpp
@@ -541,7 +541,7 @@ UnixMakefileGenerator::defaultInstall(co
     QString ret, destdir = project->first("DESTDIR").toQString();
     if(!destdir.isEmpty() && destdir.right(1) != Option::dir_sep)
         destdir += Option::dir_sep;
-    QString targetdir = fileFixify(project->first("target.path").toQString(), FileFixifyAbsolute);
+    QString targetdir = project->first("target.path").toQString();
     if(targetdir.right(1) != Option::dir_sep)
         targetdir += Option::dir_sep;
 
