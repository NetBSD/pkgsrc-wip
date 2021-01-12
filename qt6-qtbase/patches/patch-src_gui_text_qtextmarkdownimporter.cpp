$NetBSD$

* use system libmd4c

--- src/gui/text/qtextmarkdownimporter.cpp.orig	2021-01-11 17:46:02.695729653 +0000
+++ src/gui/text/qtextmarkdownimporter.cpp
@@ -48,7 +48,7 @@
 #include <QTextDocumentFragment>
 #include <QTextList>
 #include <QTextTable>
-#include "../../3rdparty/md4c/md4c.h"
+#include <md4c.h>
 
 QT_BEGIN_NAMESPACE
 
