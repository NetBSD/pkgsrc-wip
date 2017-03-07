# $NetBSD: Makefile,v 1.1 2015/04/01 13:11:38 tnn2 Exp $

# Use the commit id to obtain a snapshot of the form: 
# http://cgit.freedesktop.org/xorg/driver/xf86-video-intel/snapshot/xf86-video-intel-78d7a09b0343829c81257024b164b0b3764392ac.tar.xz

# 2017-02-28 intel: Fix checking xf86LoadKernelModule for success
COMMIT_ID=	78d7a09b0343829c81257024b164b0b3764392ac

PORTNAME=	xf86-video-intel

DISTNAME=	${PORTNAME}-${COMMIT_ID}
PKGNAME=	${PORTNAME}-2.99.917
CATEGORIES=	x11
MASTER_SITES=	http://cgit.freedesktop.org/xorg/driver/${PORTNAME}/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

# Enabled by default
# CONFIGURE_ARGS+=	--enable-dri
# CONFIGURE_ARGS+=	--enable-dri2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config automake autoconf autoreconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

# DragonFly version 4.6-RELEASE, maybe other versions prior to 4.7
# need -D_WITH_GETLINE=1 according to: 
# https://github.com/DragonFlyBSD/DPorts/issues/184
# FreeBSD ports now patches files individually.
# CFLAGS.FreeBSD+=		-D_WITH_GETLINE=1
CFLAGS.DragonFly+=		-D_WITH_GETLINE=1

# From DragonFly dports x11-drivers/xf86-video-intel29 2.99.2017.01.06
CONFIGURE_ENV.DragonFly+=	xorg_cv_cc_flag__Wno_maybe_uninitialized=no

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-intel
PKG_SUPPORTED_OPTIONS=	uxa dri3 debug
PKG_SUGGESTED_OPTIONS+=	dri3

# .if ${OPSYS} == "FreeBSD"
# PKG_SUGGESTED_OPTIONS+=	uxa
# .endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Muxa)
CONFIGURE_ARGS+=	--with-default-accel=uxa
.endif

.if !empty(PKG_OPTIONS:Mdri3)
CONFIGURE_ARGS+=	--enable-dri3
.include "../../x11/dri3proto/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dri3
.endif

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
# enable-debug crashes xorg DragonFly in __kgem_bo_map__cpu
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
CONFIGURE_ARGS+=	--enable-debug
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
# .include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
