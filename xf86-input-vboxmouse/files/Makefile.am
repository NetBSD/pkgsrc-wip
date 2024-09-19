# minimal autoconf goop to build vboxmouse outside the VirtualBox framework

vboxmouse_drv_la_LTLIBRARIES = vboxmouse_drv.la
vboxmouse_drv_la_LDFLAGS = -module -avoid-version
vboxmouse_drv_la_CFLAGS = $(CWARNFLAGS) @XORG_CFLAGS@
vboxmouse_drv_ladir = @moduledir@/drivers

vboxmouse_drv_la_SOURCES = \
vboxmouse.c
