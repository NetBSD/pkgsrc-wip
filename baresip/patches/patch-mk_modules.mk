$NetBSD$

Make sndio available for non-OpenBSD.

--- mk/modules.mk.orig	2017-05-14 06:58:08.000000000 +0000
+++ mk/modules.mk
@@ -251,7 +251,7 @@ USE_WINWAVE := yes
 MODULES   += wincons
 endif
 ifeq ($(OS),openbsd)
-MODULES   += sndio
+USE_SNDIO := yes
 endif
 ifeq ($(OS),freebsd)
 MODULES   += dtmfio
@@ -408,6 +408,9 @@ endif
 ifneq ($(USE_SNDFILE),)
 MODULES   += sndfile
 endif
+ifneq ($(USE_SNDIO),)
+MODULES   += sndio
+endif
 ifneq ($(USE_SPEEX),)
 MODULES   += speex
 endif
