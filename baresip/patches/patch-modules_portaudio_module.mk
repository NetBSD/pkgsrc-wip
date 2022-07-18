$NetBSD$

Use pkg-config to find the portaudio library.

--- modules/portaudio/module.mk.orig	2022-07-17 06:50:49.000000000 +0000
+++ modules/portaudio/module.mk
@@ -6,6 +6,7 @@
 
 MOD		:= portaudio
 $(MOD)_SRCS	+= portaudio.c
-$(MOD)_LFLAGS	+= -lportaudio
+$(MOD)_CFLAGS	+= $(shell pkg-config --cflags portaudio-2.0)
+$(MOD)_LFLAGS	+= $(shell pkg-config --libs portaudio-2.0)
 
 include mk/mod.mk
