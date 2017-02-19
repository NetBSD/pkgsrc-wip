$NetBSD: patch-src_qmldevtools_qmldevtools.pro,v 1.2 2015/10/26 19:03:59 adam Exp $

* Create libQtQmlDevTools.so for qttools.

--- src/qmldevtools/qmldevtools.pro.orig	2017-01-06 10:09:42.000000000 +0000
+++ src/qmldevtools/qmldevtools.pro
@@ -1,7 +1,8 @@
-option(host_build)
 TARGET     = QtQmlDevTools
 QT         = core-private
-CONFIG += static internal_module qmldevtools_build
+CONFIG += internal_module qmldevtools_build
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Don't use pch because the auto-generated header refers to QtBootstrap,
 # which doesn't exist
