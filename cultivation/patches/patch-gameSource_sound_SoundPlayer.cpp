$NetBSD$

Adapt for portaudio19.
From Debian.

--- gameSource/sound/SoundPlayer.cpp.orig	2006-10-02 22:29:43.000000000 +0000
+++ gameSource/sound/SoundPlayer.cpp
@@ -52,9 +52,11 @@
 
 
 // callback passed into portaudio
-static int portaudioCallback( void *inputBuffer, void *outputBuffer,
+int portaudioCallback( const void *inputBuffer, void *outputBuffer,
                               unsigned long framesPerBuffer,
-                              PaTimestamp outTime, void *userData ) {
+                              const PaStreamCallbackTimeInfo *outTime,
+                              PaStreamCallbackFlags statusFlags,
+                              void *userData ) {
 
 
     SoundPlayer *player = (SoundPlayer *)userData;
@@ -157,21 +159,13 @@ SoundPlayer::SoundPlayer( int inSampleRa
 
     if( error == paNoError ) {
     
-        error = Pa_OpenStream(
+        error = Pa_OpenDefaultStream(
             &mAudioStream,
-            paNoDevice,// default input device 
             0,              // no input 
-            paFloat32,  // 32 bit floating point input 
-            NULL,
-            Pa_GetDefaultOutputDeviceID(),
             2,          // stereo output 
             paFloat32,      // 32 bit floating point output 
-            NULL,
             mSampleRate,
             1024,   // frames per buffer
-            0,    // number of buffers, if zero then use default minimum 
-            paClipOff, // we won't output out of range samples so
-                       // don't bother clipping them 
             portaudioCallback,
             (void *)this );  // pass self-pointer to callback function
         
