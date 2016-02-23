$NetBSD$

--- osmose/OsmoseCore.cpp.orig	2011-06-06 15:24:54.000000000 +0000
+++ osmose/OsmoseCore.cpp
@@ -108,6 +108,7 @@ OsmoseCore::OsmoseCore(const char *rom_f
 
     if (emu_opt.sound == true)
     {
+#ifdef USE_SOUND
 		try
 		{
 			sndThread = new SoundThread("plughw:0,0", p->getFIFOSoundBuffer());
@@ -122,6 +123,7 @@ OsmoseCore::OsmoseCore(const char *rom_f
 			sndThread = NULL;
 			emu_opt.sound = false;
 		}
+#endif // USE_SOUND
 	}
 }
 
@@ -131,7 +133,9 @@ OsmoseCore::OsmoseCore(const char *rom_f
 OsmoseCore::~OsmoseCore()
 {
 	if (wavW != NULL) delete wavW;
+#ifdef USE_SOUND
 	if (sndThread != NULL) delete sndThread;
+#endif
 	save_bbr();	/* Save Battery backed memory if needed. */
 	delete v;
 	delete mem;
@@ -218,7 +222,9 @@ void OsmoseCore::run_frame()
         if (!p->getFIFOSoundBuffer()->spaceAvailable())
         {
             snd_started = true;
+#ifdef USE_SOUND
 			sndThread->resume();	
+#endif
         }
     }
 
