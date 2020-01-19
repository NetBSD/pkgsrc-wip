# $NetBSD: Makefile,v 1.2 2014/08/01 09:10:09 thomasklausner Exp $

DISTNAME=	xf86-video-intel-2.7.1
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver (2.7.x branch)

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
