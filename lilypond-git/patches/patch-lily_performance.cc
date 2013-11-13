$NetBSD: patch-lily_performance.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/performance.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/performance.cc
@@ -56,7 +57,7 @@ Performance::output (Midi_stream &midi_s
   for (vsize i = 0; i < audio_staffs_.size (); i++)
     {
       Audio_staff *s = audio_staffs_[i];
-      debug_output ("[" + to_string (i), true);
+      debug_output ("[" + ::to_string (i), true);
       s->output (midi_stream, i, ports_);
       debug_output ("]", false);
     }
