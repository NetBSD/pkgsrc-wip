# $NetBSD: options.mk,v 1.2 2010/08/18 10:27:27 pallegra Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gl
PKG_SUPPORTED_OPTIONS=

###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we
### 	 support.
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
     ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
     ${MACHINE_ARCH} == "sparc64") && \
    ((${OPSYS} == "NetBSD" && ${X11_TYPE} == "modular") || \
     ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
     ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux")
PKG_SUPPORTED_OPTIONS+=		dri
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-[4-9]*-*86*) && ${X11_TYPE} == "modular"
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"
PLIST_VARS+=	nodri

# XXX asm
CONFIGURE_ARGS+=	--disable-asm

.if !empty(PKG_OPTIONS:Mdri)
CONFIGURE_ARGS+=	--with-driver=dri
.  include "dri.mk"
.else
CONFIGURE_ARGS+=	--with-driver=xlib
MAKE_JOBS_SAFE=		no
PLIST.nodri=		yes
INSTALL_TARGET+=	install-osmesa
.endif
