$NetBSD$

* use posix sched_yield() instead of linux specific pthread_yield()

--- RtMidi.cpp.orig	2021-11-16 17:19:37.000000000 +0000
+++ RtMidi.cpp
@@ -3092,6 +3092,7 @@ void MidiOutWinMM :: sendMessage( const 
 #include <jack/midiport.h>
 #include <jack/ringbuffer.h>
 #include <pthread.h>
+#include <sched.h>
 #ifdef HAVE_SEMAPHORE
   #include <semaphore.h>
 #endif
@@ -3608,7 +3609,7 @@ void MidiOutJack :: sendMessage( const u
       return;
 
   while ( jack_ringbuffer_write_space(data->buff) < sizeof(nBytes) + size )
-      pthread_yield();
+      sched_yield();
 
   // Write full message to buffer
   jack_ringbuffer_write( data->buff, ( char * ) &nBytes, sizeof( nBytes ) );
