$NetBSD$

Make shared library

--- src/plugins/qmltooling/packetprotocol/packetprotocol.pro.orig	2017-01-06 10:09:42.000000000 +0000
+++ src/plugins/qmltooling/packetprotocol/packetprotocol.pro
@@ -1,6 +1,6 @@
 TARGET = QtPacketProtocol
 QT     = core-private qml-private
-CONFIG += static internal_module
+CONFIG += internal_module
 
 HEADERS = \
     qpacketprotocol_p.h \
