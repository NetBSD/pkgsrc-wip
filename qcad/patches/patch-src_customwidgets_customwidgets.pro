$NetBSD$

--- src/customwidgets/customwidgets.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/customwidgets/customwidgets.pro
@@ -36,6 +36,7 @@ HEADERS = RShortcutLineEditPlugin.h \
 #    HEADERS += RWebViewPlugin.h
 #}
 TEMPLATE = lib
-LIBS += -l$${RLIBNAME}gui -l$${RLIBNAME}core
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}gui$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL}
 DESTDIR = ../../plugins/designer
 OTHER_FILES += customwidgets.dox
