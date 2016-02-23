$NetBSD$

Fix pthread-related build errors.

--- OsmoseGUI.cpp.orig	2011-06-06 15:07:12.000000000 +0000
+++ OsmoseGUI.cpp
@@ -40,7 +40,9 @@ OsmoseGUI::OsmoseGUI(QWidget * parent, Q
 	rom_name = NULL;
 	osmoseCore = NULL;
 	saveStateSlot = 0;
-	osmose_core_mutex = PTHREAD_MUTEX_INITIALIZER;
+
+	pthread_mutex_t osmose_core_mutex;
+	pthread_mutex_init(&osmose_core_mutex, NULL);
 
 	QLogWindow::getInstance()->appendLog("Starting Osmose emulator.");
 		
@@ -347,6 +349,7 @@ OsmoseGUI::OsmoseGUI(QWidget * parent, Q
 	}
 	
 	/* Try to find a Joystick*/
+#ifdef USE_JOYSTICK
 	js0 = NULL;
 	try
 	{
@@ -363,6 +366,7 @@ OsmoseGUI::OsmoseGUI(QWidget * parent, Q
 		msg = msg + ").";
 		QLogWindow::getInstance()->appendLog(msg);
 	}
+#endif // USE_JOYSTICK
 	
 	// Enable Drop events.
 	setAcceptDrops(true);	
@@ -381,6 +385,7 @@ OsmoseGUI::~OsmoseGUI()
 
 void OsmoseGUI::configure()
 {
+#ifdef USE_JOYSTICK
 	QOsmoseConfiguration *configWindow;
 
 	if (js0 == NULL)
@@ -394,6 +399,7 @@ void OsmoseGUI::configure()
 	}
 	configWindow->exec();
 	if (js0 != NULL) js0->setListener(this);
+#endif
 }
 
 void OsmoseGUI::sizeX1()
