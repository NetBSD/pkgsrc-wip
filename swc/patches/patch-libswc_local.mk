$NetBSD$

--- libswc/local.mk.orig	2019-07-11 06:33:41.000000000 +0000
+++ libswc/local.mk
@@ -17,7 +17,7 @@ $(dir)_TARGETS +=                   \
     $(dir)/$(LIBSWC_LINK)
 endif
 
-$(dir)_PACKAGES := libdrm libinput pixman-1 wayland-server wld xkbcommon
+$(dir)_PACKAGES := libdrm pixman-1 wayland-server wld xkbcommon
 $(dir)_CFLAGS += -Iprotocol
 
 SWC_SOURCES =                       \
@@ -40,7 +40,7 @@ SWC_SOURCES =                       \
     libswc/primary_plane.c          \
     libswc/region.c                 \
     libswc/screen.c                 \
-    libswc/seat.c                   \
+    libswc/seat-ws.c                \
     libswc/shell.c                  \
     libswc/shell_surface.c          \
     libswc/shm.c                    \
