$NetBSD: patch-src_defines.pri,v 1.1 2014/12/04 15:51:25 nros Exp $
* install bash completion correctly
--- src/defines.pri.orig	2014-11-03 20:21:24.000000000 +0000
+++ src/defines.pri
@@ -111,6 +111,7 @@ else {
     launcher_folder = /usr/share/applications
     icon_folder = /usr/share/pixmaps
     hicolor_folder = /usr/share/icons/hicolor
+    bashcompletion_folder = /usr/share/bash-completion/completions
 
     !equals(d_prefix, "") {
         binary_folder = "$$d_prefix"/bin
@@ -119,6 +120,7 @@ else {
         launcher_folder = "$$d_prefix"/share/applications
         icon_folder = "$$d_prefix"/share/pixmaps
         hicolor_folder = "$$d_prefix"/share/icons/hicolor
+	bashcompletion_folder= "$$d_prefix"/share/bash-completion/completions
     }
 
     !equals(d_use_lib_path, ""):library_folder = $$d_use_lib_path
