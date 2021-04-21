# $NetBSD$

DISTNAME=	xf86-input-libinput-1.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/xorg/driver/xf86-input-libinput
COMMENT=	Generic input driver for the X.Org server based on libinput
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xorg-libinput.pc.in

ONLY_FOR_PLATFORM=	Linux-*-* FreeBSD-*-*

.include "../../wip/libinput/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
