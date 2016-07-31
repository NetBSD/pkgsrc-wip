$NetBSD$

--- shared.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ shared.pri
@@ -158,8 +158,6 @@ QMAKE_TARGET_PRODUCT = QCAD Application
 DESTDIR = $$PWD/$$ROUTDIR
 UI_DIR = .ui

-LIBS += -L$$PWD/$$ROUTDIR
-
 CONFIG(debug, debug|release) {
     !win32 {
         QMAKE_LFLAGS += -rdynamic
