$NetBSD$
--- EmulationThread.h.orig	2011-06-06 14:39:18.000000000 +0000
+++ EmulationThread.h
@@ -33,7 +33,7 @@
 
 #include <iostream>
 #include <sys/time.h>
-#include <QThread>
+#include <QtCore/QThread>
 #include <QReadWriteLock>
 #include "QGLImage.h"
 #include "OsmoseConfigurationFile.h"
