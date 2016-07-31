$NetBSD$

fix hardcoded paths

--- RSettings.cpp.orig	2016-07-01 07:13:14.000000000 +0000
+++ RSettings.cpp
@@ -133,27 +133,7 @@ bool RSettings::isDeployed() {
 }

 QString RSettings::getApplicationPath() {
-    QDir ret(QApplication::applicationDirPath());
-
-#ifdef Q_OS_MAC
-    if (ret.dirName() == "MacOS") {
-        ret.cdUp();
-        // deployed (scripts inside app bundle):
-        if (ret.cd("Resources/scripts")) {
-            ret.cdUp();
-        }
-        // development (scripts outside add bundle):
-        else {
-            ret.cdUp();
-            ret.cdUp();
-        }
-    }
-#endif
-
-    if (ret.dirName() == "debug" || ret.dirName() == "release") {
-        ret.cdUp();
-    }
-
+    QDir ret("@PREFIX@/lib/@PKGBASE@");
     return ret.path();
 }
