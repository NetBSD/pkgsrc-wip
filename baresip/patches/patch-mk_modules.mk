$NetBSD$

Make sndio available for non-OpenBSD.

--- mk/modules.mk.orig	2019-09-01 08:05:24.000000000 +0000
+++ mk/modules.mk
@@ -239,7 +239,7 @@ USE_WINWAVE := yes
 MODULES   += wincons
 endif
 ifeq ($(OS),openbsd)
-MODULES   += sndio
+USE_SNDIO := yes
 endif
 ifeq ($(OS),freebsd)
 MODULES   += dtmfio
@@ -412,6 +412,9 @@ endif
 ifneq ($(USE_SNDFILE),)
 MODULES   += sndfile
 endif
+ifneq ($(USE_SNDIO),)
+MODULES   += sndio
+endif
 ifneq ($(USE_SPEEX_PP),)
 MODULES   += speex_pp
 endif
