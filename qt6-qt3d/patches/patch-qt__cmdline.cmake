$NetBSD$

* add missing configure options so that they can be set explicitly

--- qt_cmdline.cmake.orig	2021-09-24 21:26:55.000000000 +0000
+++ qt_cmdline.cmake
@@ -1,3 +1,5 @@
+qt_commandline_option(assimp TYPE enum VALUES no qt system)
+qt_commandline_option(fbxsdk TYPE enum VALUES no qt system)
 qt_commandline_subconfig(src/core)
 qt_commandline_subconfig(src/render)
 qt_commandline_subconfig(src/plugins/geometryloaders)
