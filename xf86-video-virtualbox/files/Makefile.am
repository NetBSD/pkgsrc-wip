# minimal autoconf goop to build vboxvideo outside the VirtualBox framework

vboxvideo_drv_la_LTLIBRARIES = vboxvideo_drv.la
vboxvideo_drv_la_LDFLAGS = -module -avoid-version
vboxvideo_drv_la_CFLAGS = $(CWARNFLAGS) @XORG_CFLAGS@
vboxvideo_drv_la_CXXFLAGS = $(CWARNFLAGS) @XORG_CFLAGS@
vboxvideo_drv_ladir = @moduledir@/drivers

vboxvideo_drv_la_SOURCES = \
../../common/VBoxVideo/HGSMIBase.cpp \
../../common/VBoxVideo/HGSMIBuffers.cpp \
../../common/VBoxVideo/Modesetting.cpp \
../../common/VBoxVideo/VBVABase.cpp \
../../../GuestHost/HGSMI/HGSMICommon.cpp \
HGSMIMemAlloc.h \
VBoxVideoIPRT.h \
edid.c \
getmode.c \
hgsmimemalloc.c \
pointer.c \
setmode.c \
vboxvideo.c \
vboxvideo.h \
vbva.c
