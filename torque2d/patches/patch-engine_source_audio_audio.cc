$NetBSD$

--- engine/source/audio/audio.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/audio/audio.cc
@@ -2499,7 +2499,7 @@ bool OpenALInit()
       return false;
 
    // Create an openAL context
-#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
    int freq = Con::getIntVariable("Pref::Unix::OpenALFrequency");
    if (freq == 0)
       freq = 22050;
@@ -2529,7 +2529,7 @@ bool OpenALInit()
       return false;
 
    // Make this context the active context
-#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_EMSCRIPTEN) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_EMSCRIPTEN) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
    alcMakeContextCurrent((ALCcontext*)mContext);
 #else
    alcMakeContextCurrent(mContext);
@@ -2629,7 +2629,7 @@ void OpenALShutdown()
 
    if (mContext)
    {
-#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
 	   alcDestroyContext((ALCcontext*)mContext);
 #elif defined(TORQUE_OS_EMSCRIPTEN)
       alcDestroyContext((ALCcontext*)mContext);
@@ -2641,7 +2641,7 @@ void OpenALShutdown()
    }
    if (mDevice)
    {
-#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD)
+#if defined(TORQUE_OS_ANDROID) || defined(TORQUE_OS_LINUX) || defined(TORQUE_OS_OPENBSD) || defined(TORQUE_OS_NETBSD)
 	   alcCloseDevice((ALCdevice*)mDevice);
 #elif defined(TORQUE_OS_EMSCRIPTEN)
       alcCloseDevice((ALCdevice*)mDevice);
