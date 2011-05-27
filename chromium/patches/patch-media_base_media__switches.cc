$NetBSD: patch-media_base_media__switches.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- media/base/media_switches.cc.orig	2011-05-24 08:01:03.000000000 +0000
+++ media/base/media_switches.cc
@@ -6,7 +6,7 @@
 
 namespace switches {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_DRAGONFLY)
 // The Alsa device to use when opening an audio stream.
 const char kAlsaOutputDevice[] = "alsa-output-device";
 // The Alsa device to use when opening an audio input stream.
