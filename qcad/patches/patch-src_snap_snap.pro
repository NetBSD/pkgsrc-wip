$NetBSD$

--- src/snap/snap.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/snap/snap.pro
@@ -45,6 +45,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}snap
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}grid -l$${RLIBNAME}entity
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}grid$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL}
 OTHER_FILES += snap.dox
 DEFINES += QCADSNAP_LIBRARY
