$NetBSD$

--- src/grid/grid.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/grid/grid.pro
@@ -13,4 +13,4 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}grid
-LIBS += -l$${RLIBNAME}core
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL}
