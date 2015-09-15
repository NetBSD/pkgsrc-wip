# minimal autoconf goop to build vboxvideo outside the VirtualBox framework

vboxvideo_drv_la_LTLIBRARIES = vboxvideo_drv.la
vboxvideo_drv_la_LDFLAGS = -module -avoid-version
vboxvideo_drv_la_CFLAGS = $(CWARNFLAGS) @XORG_CFLAGS@
vboxvideo_drv_ladir = @moduledir@/drivers

vboxvideo_drv_la_SOURCES = \
getmode.c \
helpers.c \
pointer.c \
setmode.c \
vboxvideo.c \
vboxvideo.h \
vboxvideo_dri2.c \
vbva.c
