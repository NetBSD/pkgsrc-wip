$NetBSD: patch-src_3rdparty_qtsingleapplication_qtlocalpeer.cpp,v 1.1 2011/02/24 18:51:35 ryo-on Exp $

* Fix build on DragonFly 2.8.2

--- src/3rdparty/qtsingleapplication/qtlocalpeer.cpp.orig	2010-11-16 20:24:09 +0000
+++ src/3rdparty/qtsingleapplication/qtlocalpeer.cpp
@@ -45,6 +45,7 @@
 ****************************************************************************/
 
 
+#include "errno.h"
 #include "qtlocalpeer.h"
 #include <QtCore/QCoreApplication>
 #include <QtCore/QTime>
