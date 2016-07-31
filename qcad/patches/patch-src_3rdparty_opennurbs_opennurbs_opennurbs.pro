$NetBSD$

--- src/3rdparty/opennurbs/opennurbs/opennurbs.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/3rdparty/opennurbs/opennurbs/opennurbs.pro
@@ -218,14 +218,8 @@ HEADERS += \

 TARGET = opennurbs
 TEMPLATE = lib
-CONFIG += staticlib
-CONFIG(release, debug|release) {
-    LIBS += -L../zlib/release
-}
-else {
-    LIBS += -L../zlib/debug
-}
-LIBS += -lzlib
+CONFIG += plugin
+LIBS += ../../../../$${ROUTDIR}/$${RLIBPRE}zlib$${RLIBPOSTDLL}
 win32 {
     #DEFINES += ON_DLL_EXPORTS ON_COMPILING_OPENNURBS NDEBUG
     DEFINES += ON_COMPILING_OPENNURBS NDEBUG
