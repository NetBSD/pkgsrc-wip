$NetBSD$

Make sndio available for non-OpenBSD.

--- mk/modules.mk.orig	2018-07-04 14:22:24.000000000 +0000
+++ mk/modules.mk
@@ -250,7 +250,7 @@ USE_WINWAVE := yes
 MODULES   += wincons
 endif
 ifeq ($(OS),openbsd)
-MODULES   += sndio
+USE_SNDIO := yes
 endif
 ifeq ($(OS),freebsd)
 MODULES   += dtmfio
@@ -414,6 +414,9 @@ endif
 ifneq ($(USE_SNDFILE),)
 MODULES   += sndfile
 endif
+ifneq ($(USE_SNDIO),)
+MODULES   += sndio
+endif
 ifneq ($(USE_SPEEX_AEC),)
 MODULES   += speex_aec
 endif
