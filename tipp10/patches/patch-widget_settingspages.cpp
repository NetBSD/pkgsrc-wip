$NetBSD: patch-widget_settingspages.cpp,v 1.1 2012/12/29 14:51:33 othyro Exp $

Remove unnecessary qualifier.

--- widget/settingspages.cpp.orig	2011-03-12 20:10:08.000000000 +0000
+++ widget/settingspages.cpp
@@ -501,7 +501,7 @@ void DatabasePage::writeSettings() {
 	QSettings settings;
 	#endif
 	settings.beginGroup("database");
-	settings.setValue("pathpro", lineDatabasePath->text() + "/" + QString::QString(APP_USER_DB));
+	settings.setValue("pathpro", lineDatabasePath->text() + "/" + QString(APP_USER_DB));
 	settings.endGroup();
 }
 
