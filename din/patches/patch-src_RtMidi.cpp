$NetBSD: patch-src_RtMidi.cpp,v 1.1 2023/09/12 07:55:11 fox Exp $

Use process scheduling from NetBSD instead of pthread.

--- src/RtMidi.cpp.orig	2023-06-26 10:02:16.000000000 +0000
+++ src/RtMidi.cpp
@@ -3607,7 +3607,9 @@ void MidiOutJack :: sendMessage( const u
   if ( size + sizeof(nBytes) > (size_t) data->buffMaxWrite )
       return;
 
-  while ( jack_ringbuffer_write_space(data->buff) < sizeof(nBytes) + size )
+  while ( jack_ringbuffer_write_space(data->buff) < sizeof(nBytes) + size )#if defined(__NetBSD__)
+      sched_yield();
+#else
       pthread_yield();
 
   // Write full message to buffer
