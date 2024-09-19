# $NetBSD: Makefile,v 1.49 2019/03/19 23:51:46 wiz Exp $

# 2019-04-24	Retry get_fb_ptr in get_fb
COMMIT_ID=	d1d8e3c8d0a0a0394d395eba171460501745209b

# 2019-03-19	Bump version for 19.0.1 release
# COMMIT_ID=	36703f66c3b06875651606a6280d5dc9d9dad51e

# 2019-03-15	modesetting: add tile property support
# COMMIT_ID=	4407c78bd86da4460ee07a15a365e07d99e0dd27

PORTNAME=	xf86-video-ati

DISTNAME=	${PORTNAME}-${COMMIT_ID}
PKGNAME=	${PORTNAME}-19.0.1
# PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://cgit.freedesktop.org/xorg/driver/${PORTNAME}/snapshot/
EXTRACT_SUFX=	.tar.xz

# DISTNAME=	xf86-video-ati-18.1.0
# CATEGORIES=	x11
# MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
# EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver
LICENSE=	mit AND x11

CONFIGURE_ARGS+=	--enable-dri

CONFLICTS+=	xf86-video-ati6-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
# USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-ati
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUPPORTED_OPTIONS+=	revert_gbm_bo

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	revert_gbm_bo
.endif

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--enable-glamor

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
.endif

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

# Revert: Use gbm as much as possible for bo allocation
# 2018-07-09 18:28:21 +0200
# https://cgit.freedesktop.org/xorg/driver/xf86-video-ati
# commit	3c4c0213c11d623cba7adbc28dde652694f2f758
.if !empty(PKG_OPTIONS:Mrevert_gbm_bo)
CPPFLAGS+=	-DREVERT_GBM_BO
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18.1
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.58
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
