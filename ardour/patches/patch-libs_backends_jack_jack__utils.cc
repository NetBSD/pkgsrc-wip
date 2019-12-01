$NetBSD$

Realtime JACK currently doesn't work on NetBSD.

This also means it's inadvisable to set the period count.
Let the system worry about latency and don't endure terrible output quality.

--- libs/backends/jack/jack_utils.cc.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_utils.cc
@@ -485,8 +485,12 @@ ARDOUR::get_jack_audio_driver_supports_l
 bool
 ARDOUR::get_jack_audio_driver_supports_setting_period_count (const string& driver)
 {
+#ifdef __NetBSD__
+	return false;
+#else
 	return !(driver == dummy_driver_name || driver == coreaudio_driver_name ||
 			driver == portaudio_driver_name);
+#endif
 }
 
 bool
@@ -664,7 +668,11 @@ ARDOUR::JackCommandLineOptions::JackComm
 	, timeout(0)
 	, no_mlock(false)
 	, ports_max(128)
+#ifdef __NetBSD__
+	, realtime(false)
+#else
 	, realtime(true)
+#endif
 	, priority(0)
 	, unlock_gui_libs(false)
 	, verbose(false)
