PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-input-mouse
# dflyu4b is for DragonFly BSD newer USB stack, ported from newer FreeBSD
#     #include <bus/u4b/usb.h>
# dflyusb is for DragonFly BSD older USB stack, OS version < 300703
#     #include <bus/usb/usb.h>
# fbsdusb is for FreeBSD USB stack 
#     #include <dev/usb/usb.h>
PKG_SUPPORTED_OPTIONS=	dflyu4b dflyusb fbsdusb 
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "DragonFly"
.  if !empty(OS_VERSION:M[0-2].*) || !empty(OS_VERSION:M3.0*)
PKG_SUGGESTED_OPTIONS+=	dflyusb 
.  else
# Assume Dragonfly 3.1 - 3.6 users built U4B stack
# 3.8 and after U4B is the default
PKG_SUGGESTED_OPTIONS+=	dflyu4b 
.  endif
.endif

.if ${OPSYS} == "FreeBSD"
PKG_SUGGESTED_OPTIONS+=	fbsdusb
.endif

.if !empty(PKG_OPTIONS:Mdflyu4b) || !empty(PKG_OPTIONS:Mdflyusb) || !empty(PKG_OPTIONS:Mfbsdusb)
CPPFLAGS+=	-DFREEBSD_USB
.endif

.if !empty(PKG_OPTIONS:Mdflyu4b)
CPPFLAGS+=	-DDRAGONFLY_U4B
.endif

.if !empty(PKG_OPTIONS:Mdflyusb)
CPPFLAGS+=	-DDRAGONFLY_USB
.endif

.if !empty(PKG_OPTIONS:Mdflyu4b) || !empty(PKG_OPTIONS:Mdflyusb) || !empty(PKG_OPTIONS:Mfbsdusb)
SUBST_CLASSES+=			freebsdusb 
SUBST_STAGE.freebsdusb=		post-extract
SUBST_MESSAGE.freebsdusb=	Patching src/Makefile.in for DragonFly or FreeBSD compatible USB 
SUBST_FILES.freebsdusb+=	src/Makefile.in
SUBST_SED.freebsdusb+=		-e 's|-module -avoid-version|-module -avoid-version -lusbhid|'
.endif
