# $NetBSD: Makefile,v 1.39 2016/12/07 21:59:54 wiz Exp $

DISTNAME=	xf86-video-intel-2.99.917
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

# From FreeBSD ports / DragonFly dports
# DragonFly version 4.6-RELEASE, maybe other versions prior to 4.7
# need -D_WITH_GETLINE=1 according to: 
# https://github.com/DragonFlyBSD/DPorts/issues/184
CFLAGS.FreeBSD+=		-D_WITH_GETLINE=1
CONFIGURE_ENV.FreeBSD+=		xorg_cv_cc_flag__Wno_maybe_uninitialized=no
CFLAGS.DragonFly+=		-D_WITH_GETLINE=1
CONFIGURE_ENV.DragonFly+=	xorg_cv_cc_flag__Wno_maybe_uninitialized=no

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-intel
PKG_SUPPORTED_OPTIONS=	debug xvmc

.include "../../mk/bsd.options.mk"

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_VARS+=		xvmc	

.if !empty(PKG_OPTIONS:Mxvmc)
.include "../../x11/xcb-util/buildlink3.mk"
PLIST.xvmc=		yes
.endif

.include "../../devel/xorg-util-macros/buildlink3.mk"

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
