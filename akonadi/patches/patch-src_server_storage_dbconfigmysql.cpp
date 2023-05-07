--- src/server/storage/dbconfigmysql.cpp	2023-05-07 21:54:06.388101591 +0200
+++ src/server/storage/dbconfigmysql.cpp.orig	2023-05-07 21:52:56.240982968 +0200
@@ -256,7 +256,8 @@
 
     QFile actualFile(actualConfig);
     // update conf only if either global (or local) is newer than actual
-    if (true) {
+    if ((QFileInfo(globalConfig).lastModified() > QFileInfo(actualFile).lastModified())
+        || (QFileInfo(localConfig).lastModified() > QFileInfo(actualFile).lastModified())) {
         QFile globalFile(globalConfig);
         QFile localFile(localConfig);
         if (globalFile.open(QFile::ReadOnly) && actualFile.open(QFile::WriteOnly)) {
