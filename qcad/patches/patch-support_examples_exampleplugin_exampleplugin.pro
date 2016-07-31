$NetBSD$

--- support/examples/exampleplugin/exampleplugin.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ support/examples/exampleplugin/exampleplugin.pro
@@ -6,4 +6,6 @@ TEMPLATE    = lib
 HEADERS     = RExamplePlugin.h
 SOURCES     = RExamplePlugin.cpp
 DESTDIR     = ../../../plugins
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}gui -l$${RLIBNAME}ecmaapi
+LIBS += ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}gui$${RLIBPOSTDLL} \
+	../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}ecmaapi$${RLIBPOSTDLL}
