--- src/exportoofiledialog.cpp.orig	2021-06-16 16:05:40.548415166 +0000
+++ src/exportoofiledialog.cpp
@@ -36,7 +36,7 @@
 {
     setFileMode(QFileDialog::AnyFile);
     QDir d;
-    d.setPath("/usr/share/vym/exports");
+    d.setPath("@PREFIX@/share/vym/exports");
     scanExportConfigs(d);
     d.setPath(d.homePath() + "/.vym/exports");
     scanExportConfigs(d);
