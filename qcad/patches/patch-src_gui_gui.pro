$NetBSD$

--- src/gui/gui.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/gui/gui.pro
@@ -80,7 +80,8 @@ else {
     CONFIG += plugin
 }

-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL}
 NAME = $${RLIBNAME}gui
 TARGET = $${NAME}
 OTHER_FILES += gui.dox
