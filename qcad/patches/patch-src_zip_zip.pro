$NetBSD$

--- src/zip/zip.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/zip/zip.pro
@@ -23,7 +23,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}zip
-LIBS += -l$${RLIBNAME}core -lquazip
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}quazip$${RLIBPOSTDLL}
 OTHER_FILES += zip.dox
 DEFINES += QCADZIP_LIBRARY
