# $NetBSD: Makefile,v 1.30 2018/06/19 07:12:45 wiz Exp $

DISTNAME=	xf86-input-mouse-1.9.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg mouse driver
LICENSE=	mit

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4
CFLAGS.DragonFly+=	-Wno-array-bounds

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
SUBST_CLASSES+=			freebsdusb
SUBST_STAGE.freebsdusb=		post-extract
SUBST_MESSAGE.freebsdusb=	Patching src/Makefile.in for DragonFly or FreeBSD compatible USB
SUBST_FILES.freebsdusb+=	src/Makefile.in
SUBST_SED.freebsdusb+=		-e 's|-module -avoid-version|-module -avoid-version -lusbhid|'
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-input-mouse
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CPPFLAGS+=		-DDEBUG
CFLAGS+=		-O0 -g3
.endif

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
