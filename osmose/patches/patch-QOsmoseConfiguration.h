$NetBSD$

--- QOsmoseConfiguration.h.orig	2011-06-06 15:07:54.000000000 +0000
+++ QOsmoseConfiguration.h
@@ -36,7 +36,11 @@
 #include <QMessageBox>
 #include "ui_Configuration.h"
 #include "KeyMapper.h"
+
+#ifdef USE_JOYSTICK
 #include "Joystick.h"
+#endif
+
 #include "OsmoseConfigurationFile.h"
 
 class KeyGrabber : public QDialog
@@ -53,7 +57,9 @@ protected:
 	unsigned int keyPressed;
 };
 
-class QOsmoseConfiguration : public QDialog, public JoystickListener, private Ui::Configuration
+class QOsmoseConfiguration :
+	public QDialog,
+	private Ui::Configuration
 {
 
 Q_OBJECT
