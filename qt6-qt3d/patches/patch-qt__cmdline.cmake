$NetBSD$

* add missing configure options so that they can be set explicitly

--- qt_cmdline.cmake.orig	2021-02-08 08:36:53.338168919 +0000
+++ qt_cmdline.cmake
@@ -0,0 +1,2 @@
+qt_commandline_option(assimp TYPE enum VALUES no qt system)
+qt_commandline_option(fbxsdk TYPE enum VALUES no qt system)
