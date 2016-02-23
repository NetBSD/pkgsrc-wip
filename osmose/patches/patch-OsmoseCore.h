$NetBSD$

--- osmose/OsmoseCore.h.orig	2011-06-06 15:25:26.000000000 +0000
+++ osmose/OsmoseCore.h
@@ -56,7 +56,10 @@
 #include "TGAWriter.h"
 #include "QLogWindow.h"
 #include "Pthreadcpp.h"
+
+#ifdef USE_SOUND
 #include "SoundThread.h"
+#endif
 
 using namespace std;
 
@@ -136,7 +139,9 @@ class OsmoseCore : public DebugEventThro
         void save_bbr();				// Save Battery Backed Ram.
         
         void displayTiles(unsigned int *s, VDP *vd, int tile, int x, int y);
+#ifdef USE_SOUND
 		SoundThread *sndThread;
+#endif
 		OsmoseConfigurationFile *configuration;
 		pthread_mutex_t *osmose_core_mutex;
 };
