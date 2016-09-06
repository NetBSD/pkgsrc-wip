$NetBSD$

Enable the experimental jack module. This provides an alternative for
audio on systems where the full duplex oss/portaudio (opened separately
for read and write) gives problems.

Make sndio available for non-OpenBSD.

--- mk/modules.mk.orig	2016-07-22 19:17:45.000000000 +0000
+++ mk/modules.mk
@@ -241,7 +241,7 @@ USE_WINWAVE := yes
 MODULES   += wincons
 endif
 ifeq ($(OS),openbsd)
-MODULES   += sndio
+USE_SNDIO := yes
 endif
 ifeq ($(OS),freebsd)
 MODULES   += dtmfio
@@ -355,6 +355,9 @@ endif
 ifneq ($(USE_ISAC),)
 MODULES   += isac
 endif
+ifneq ($(USE_JACK),)
+MODULES   += jack
+endif
 ifneq ($(USE_L16),)
 MODULES   += l16
 endif
@@ -394,6 +397,9 @@ endif
 ifneq ($(USE_SNDFILE),)
 MODULES   += sndfile
 endif
+ifneq ($(USE_SNDIO),)
+MODULES   += sndio
+endif
 ifneq ($(USE_SPEEX),)
 MODULES   += speex
 endif
