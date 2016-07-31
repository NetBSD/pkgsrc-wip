$NetBSD$

--- src/entity/entity.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/entity/entity.pro
@@ -119,7 +119,8 @@ NAME = $${RLIBNAME}entity
 TARGET = $${NAME}
 OTHER_FILES += entity.dox
 DEFINES += QCADENTITY_LIBRARY
-LIBS += -l$${RLIBNAME}core -lopennurbs
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}opennurbs$${RLIBPOSTDLL}
 !win32 {
     include( ../../shared_ts.pri )
 }
