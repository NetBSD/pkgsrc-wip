$NetBSD$

--- OsmoseGUI.h.orig	2011-06-06 15:07:18.000000000 +0000
+++ OsmoseGUI.h
@@ -49,11 +49,14 @@
 #include "OsmoseCore.h"
 #include "MemoryMapper.h"
 #include "QLogWindow.h"
+
+#ifdef USE_JOYSTICK
 #include "Joystick.h"
+#endif // USE_JOYSTICK
 
 #define MENU_HEIGHT	20
 
-class OsmoseGUI : public QMainWindow, JoystickListener
+class OsmoseGUI : public QMainWindow
 {
 	Q_OBJECT;
 	
@@ -131,7 +134,9 @@ private:
 	void updateMachineMenu();
 	void loadTheROM(QString name);
 	bool isFullscreen;
+#ifdef USE_JOYSTICK
 	Joystick *js0;
+#endif
 };
 
 #endif	// OsmoseGUI
