$NetBSD$

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/entity/entity.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/entity/entity.pro
@@ -117,9 +117,11 @@ else {
 }
 NAME = $${RLIBNAME}entity
 TARGET = $${NAME}
+INSTALLS += target
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../3rdparty/opennurbs/opennurbs -lopennurbs
 !win32 {
     include( ../../shared_ts.pri )
 }
