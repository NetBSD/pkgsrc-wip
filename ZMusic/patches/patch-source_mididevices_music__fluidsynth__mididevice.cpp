$NetBSD$

Also search for libfluidsynth.so.3, which is the current version installed by pkgsrc.

--- source/mididevices/music_fluidsynth_mididevice.cpp.orig	2020-10-16 08:54:25.000000000 +0000
+++ source/mididevices/music_fluidsynth_mididevice.cpp
@@ -142,6 +142,7 @@ protected:
 #else // !__APPLE__
 #define FLUIDSYNTHLIB1	"libfluidsynth.so.1"
 #define FLUIDSYNTHLIB2	"libfluidsynth.so.2"
+#define FLUIDSYNTHLIB3	"libfluidsynth.so.3"
 #endif // __APPLE__
 #endif
 
@@ -547,7 +548,7 @@ bool FluidSynthMIDIDevice::LoadFluidSynt
 			return true;
 	}
 
-	if(!FluidSynthModule.Load({FLUIDSYNTHLIB1, FLUIDSYNTHLIB2}))
+	if(!FluidSynthModule.Load({FLUIDSYNTHLIB1, FLUIDSYNTHLIB2, FLUIDSYNTHLIB3}))
 	{
 		ZMusic_Printf(ZMUSIC_MSG_ERROR, "Could not load " FLUIDSYNTHLIB1 " or " FLUIDSYNTHLIB2 "\n");
 		return false;
