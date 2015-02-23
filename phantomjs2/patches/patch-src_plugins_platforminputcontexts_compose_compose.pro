$NetBSD: patch-src_plugins_platforminputcontexts_compose_compose.pro,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

PR pkg/48553

--- src/qt/qtbase/src/plugins/platforminputcontexts/compose/compose.pro.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtbase/src/plugins/platforminputcontexts/compose/compose.pro
@@ -16,6 +16,8 @@ SOURCES += $$PWD/main.cpp \
 HEADERS += $$PWD/qcomposeplatforminputcontext.h \
            $$PWD/generator/qtablegenerator.h \
 
+DEFINES += X11BASE=\\\"$$(X11BASE)\\\"
+
 # libxkbcommon
 contains(QT_CONFIG, xkbcommon-qt): {
     # dont't need x11 dependency for compose key plugin
