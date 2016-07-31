$NetBSD$

--- src/operations/operations.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/operations/operations.pro
@@ -41,6 +41,7 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}operations
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL}
 OTHER_FILES += operations.dox
 DEFINES += QCADOPERATIONS_LIBRARY
