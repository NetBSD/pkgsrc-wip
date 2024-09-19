$NetBSD: patch-m64p__install.sh,v 1.1 2013/07/06 23:00:14 othyro Exp $

Disable the GlideHQ plugin for now, because it doesn't build on NetBSD.

--- m64p_install.sh.orig	2013-02-26 20:22:09.000000000 +0000
+++ m64p_install.sh
@@ -28,7 +28,7 @@ if [ -z "$MAKE" ]; then
 fi
 
 if [ -z "$M64P_COMPONENTS" ]; then
-	M64P_COMPONENTS="core rom ui-console audio-sdl input-sdl rsp-hle video-rice video-glide64mk2"
+	M64P_COMPONENTS="core rom ui-console audio-sdl input-sdl rsp-hle video-rice"
 fi
 
 for component in ${M64P_COMPONENTS}; do
