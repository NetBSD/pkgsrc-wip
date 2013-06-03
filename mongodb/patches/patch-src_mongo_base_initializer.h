$NetBSD: patch-src_mongo_base_initializer.h,v 1.1 2013/06/03 13:58:35 fhajny Exp $

Fixes at least SunOS.
--- src/mongo/base/initializer.h.orig	2013-05-30 12:52:25.408767013 +0000
+++ src/mongo/base/initializer.h	2013-05-30 12:50:56.078895696 +0000
@@ -17,6 +17,7 @@
 
 #include <string>
 #include <vector>
+#include <unistd.h>
 
 #include "mongo/base/configuration_variable_manager.h"
 #include "mongo/base/disallow_copying.h"
