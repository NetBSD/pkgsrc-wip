$NetBSD$

--- audio/midi/FluidSynthMidiDriver.cpp.orig	2006-11-14 20:13:50.000000000 +0200
+++ audio/midi/FluidSynthMidiDriver.cpp	2006-11-15 00:08:31.000000000 +0200
@@ -21,6 +21,8 @@
 #include "pent_include.h"
 #include "FluidSynthMidiDriver.h"
 
+#include <cstdlib>
+
 #ifdef USE_FLUIDSYNTH_MIDI
 
 //#include <cstring>
@@ -81,7 +83,10 @@
 	// The default gain setting is ridiculously low, but we can't set it
 	// too high either or sound will be clipped. This may need tuning...
 
-	setNum("synth.gain", 2.1);
+	std::string synthgain = getConfigSetting("fluidsynth_gain", "2.1");
+        double gain = atof(synthgain.c_str());
+	setNum("synth.gain", gain);
+
 	setNum("synth.sample-rate", sample_rate);
 
 	_synth = new_fluid_synth(_settings);
