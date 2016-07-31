$NetBSD$

--- src/io/dxf/dxf.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/io/dxf/dxf.pro
@@ -16,7 +16,11 @@ SOURCES = \
     RDxfPlugin.cpp
 TEMPLATE = lib
 DEFINES += QCADDXF_LIBRARY
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity -ldxflib -l$${RLIBNAME}operations
+LIBS += ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}dxflib$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}operations$${RLIBPOSTDLL}
+
 r_static_libs {
     CONFIG -= plugin
     CONFIG += staticlib
@@ -25,4 +29,4 @@ else {
     DESTDIR = ../../../plugins
 }

-POST_TARGETDEPS += ../../../$$ROUTDIR/$${RLIBPRE}dxflib$${RLIBPOST}
+#POST_TARGETDEPS += ../../../$${ROUTDIR}/$${RLIBPRE}dxflib$${RLIBPOSTDLL}
