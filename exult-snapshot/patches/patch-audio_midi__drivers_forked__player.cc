$NetBSD$

--- audio/midi_drivers/forked_player.cc.orig	2017-05-13 09:27:33.000000000 +0000
+++ audio/midi_drivers/forked_player.cc
@@ -39,7 +39,11 @@ const MidiDriver::MidiDriverDesc forked_
 // NB: This function doesn't return unless execlp fails!
 static  void    playFJmidifile(const char *name)
 {
+#ifdef __NetBSD__
+	execlp("midiplay","midiplay","-v","-v",name,static_cast<char *>0);
+#else
 	execlp("playmidi","playmidi","-v","-v","-e",name,static_cast<char *>(0));
+#endif
 }
 
 forked_player::forked_player() : repeat_(false), forked_job(-1)
