$NetBSD$

Treat NetBSD like FreeBSD.

--- src/framework/audio/audiomodule.cpp.orig	2025-07-21 11:28:58.183733089 +0000
+++ src/framework/audio/audiomodule.cpp
@@ -62,7 +62,7 @@ using namespace muse::audio::fx;
 #include "internal/platform/lin/linuxaudiodriver.h"
 #endif
 
-#ifdef Q_OS_FREEBSD
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include "internal/platform/lin/linuxaudiodriver.h"
 #endif
 #ifdef Q_OS_WIN
@@ -122,7 +122,7 @@ void AudioModule::registerExports()
     m_audioDriver = std::shared_ptr<IAudioDriver>(new JackAudioDriver());
 #else
 
-#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     m_audioDriver = std::shared_ptr<IAudioDriver>(new LinuxAudioDriver());
 #endif
 
