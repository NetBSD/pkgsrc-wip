$NetBSD: patch-src_tools_bootstrap_bootstrap.pro,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Create shared library .so file fo libQt5Bootstrap.la.

--- src/qt/qtbase/src/tools/bootstrap/bootstrap.pro.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/tools/bootstrap/bootstrap.pro
@@ -1,4 +1,4 @@
-option(host_build)
+#option(host_build)
 
 TARGET = QtBootstrap
 QT =
