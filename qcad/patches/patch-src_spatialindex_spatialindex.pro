$NetBSD$

--- src/spatialindex/spatialindex.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/spatialindex/spatialindex.pro
@@ -14,7 +14,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}spatialindex
-LIBS += -l$${RLIBNAME}core -lspatialindexnavel
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}spatialindexnavel$${RLIBPOSTDLL}
 OTHER_FILES += spatialindex.dox
 DEFINES += QCADSPATIALINDEX_LIBRARY
