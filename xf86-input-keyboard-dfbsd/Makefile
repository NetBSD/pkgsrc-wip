# $NetBSD: Makefile,v 1.26 2018/03/07 11:57:41 wiz Exp $

DISTNAME=	xf86-input-keyboard-1.9.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg keyboard driver
LICENSE=	mit

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-input-keyboard
PKG_SUPPORTED_OPTIONS=	debug
# PKG_SUGGESTED_OPTIONS=  debug

PKG_SUPPORTED_OPTIONS+=	delay_kdsetled
.if ${OPSYS} == "DragonFly"
# PKG_SUGGESTED_OPTIONS+=  delay_kdsetled
.endif

.include "../../mk/bsd.options.mk"

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CPPFLAGS+=		-DDEBUG
CFLAGS+=		-O0 -g3
.endif

.if !empty(PKG_OPTIONS:Mdelay_kdsetled)
CPPFLAGS+=		-DDELAY_KDSETLED
.endif

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
