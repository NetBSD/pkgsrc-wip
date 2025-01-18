$NetBSD: patch-librecad_src_main_qc__applicationwindow.cpp,v 1.2 2019/10/26 12:23:01 kamil Exp $

ignore files in the plugins directory that do not contain '.so', as
pkgsrc leaves some .la files there

--- librecad/src/main/qc_applicationwindow.cpp.orig	2025-01-14 00:44:20.000000000 +0000
+++ librecad/src/main/qc_applicationwindow.cpp
@@ -702,6 +702,10 @@ void QC_ApplicationWindow::loadPlugins()
             if (!fileName.contains(".dylib"))
                 continue;
             #endif
+            #if defined(Q_OS_UNIX)
+            if (!fileName.contains(".so"))
+                continue;
+            #endif
 #if (defined (_WIN32) || defined (_WIN32) || defined (_WIN64))
             if (!fileName.contains(".dll"))
                 continue;
