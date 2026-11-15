$NetBSD$

* Don't use asm-generic/errno.h
* Missing ESTRPIPE on NetBSD

--- src/webrtc/src/modules/audio_device/linux/audio_device_alsa_linux.cc.orig	2026-11-11 19:28:52.284783059 +0000
+++ src/webrtc/src/modules/audio_device/linux/audio_device_alsa_linux.cc
@@ -10,7 +10,7 @@
 
 #include "modules/audio_device/linux/audio_device_alsa_linux.h"
 
-#include <asm-generic/errno.h>
+//#include <asm-generic/errno.h>
 
 #include <cerrno>
 #include <cstdint>
@@ -33,6 +33,10 @@
 #include <X11/Xlib.h>
 #endif
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 WebRTCAlsaSymbolTable* GetAlsaSymbolTable() {
   static WebRTCAlsaSymbolTable* alsa_symbol_table = []() {
     auto* table = new WebRTCAlsaSymbolTable();
