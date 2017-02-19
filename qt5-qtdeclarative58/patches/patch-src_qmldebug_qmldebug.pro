$NetBSD$

Make shared library

--- src/qmldebug/qmldebug.pro.orig	2017-01-06 10:09:42.000000000 +0000
+++ src/qmldebug/qmldebug.pro
@@ -1,6 +1,6 @@
 TARGET    =  QtQmlDebug
 QT        =  core-private network packetprotocol-private qml-private
-CONFIG    += static internal_module
+CONFIG    += internal_module
 
 load(qt_module)
 
