$NetBSD$

Add QDropEvent, allow build with Qt>=5.15

--- src/libtextosaurus/definitions/definitions.h.orig	2019-12-16 06:44:19.000000000 +0000
+++ src/libtextosaurus/definitions/definitions.h
@@ -4,6 +4,7 @@
 #define DEFINITIONS_H
 
 #include <QtGlobal>
+#include <QDropEvent>
 
 #include "3rd-party/scintilla/include/Scintilla.h"
 
