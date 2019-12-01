$NetBSD$

Realtime JACK currently doesn't work on NetBSD.

--- libs/backends/jack/jack_audiobackend.cc.orig	2017-09-15 20:56:23.000000000 +0000
+++ libs/backends/jack/jack_audiobackend.cc
@@ -504,7 +504,11 @@ JACKAudioBackend::setup_jack_startup_com
 	if (_target_sample_format == FormatInt16) {
 		options.force16_bit = _target_sample_format;
 	}
+#ifdef __NetBSD__
+	options.realtime = false;
+#else
 	options.realtime = true;
+#endif
 	options.ports_max = 2048;
 
 	ARDOUR::set_midi_option (options, _target_midi_option);
