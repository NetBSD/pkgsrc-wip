# $NetBSD: Makefile,v 1.47 2018/09/16 20:28:51 triaxx Exp $

DISTNAME=	xf86-video-ati-18.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver
LICENSE=	mit AND x11

CONFIGURE_ARGS+=	--enable-dri

CONFLICTS+=	xf86-video-ati6-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-ati
PKG_SUPPORTED_OPTIONS=  debug
PKG_SUPPORTED_OPTIONS+= revert_gbm_bo

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+= revert_gbm_bo
.endif

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--enable-glamor

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
.endif

# Revert: Use gbm as much as possible for bo allocation
# 2018-07-09 18:28:21 +0200
# https://cgit.freedesktop.org/xorg/driver/xf86-video-ati
# commit	3c4c0213c11d623cba7adbc28dde652694f2f758
.if !empty(PKG_OPTIONS:Mrevert_gbm_bo)
CPPFLAGS+=	-DREVERT_GBM_BO
.endif

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18.1
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.58
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
