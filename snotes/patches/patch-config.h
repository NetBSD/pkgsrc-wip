$NetBSD: patch-config.h,v 1.1 2012/12/17 22:15:50 othyro Exp $

Removing extra qualifier on parseConfig().

--- config.h.orig	2005-02-04 16:58:28.000000000 +0000
+++ config.h
@@ -64,7 +64,7 @@ class Config : public QWidget {
 		static bool parseConfig(QString * inp, QFont * out);
 		static bool parseConfig(QString * inp, int * out);
 		static bool parseConfig(QString *inp, QWidget *out);
-		static bool Config::parseConfig(QString *inp, AlarmTimeStamp *out);
+		static bool parseConfig(QString *inp, AlarmTimeStamp *out);
 
 		void keyPressEvent (QKeyEvent *e);
 		
