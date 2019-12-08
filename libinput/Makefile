# $NetBSD$

DISTNAME=	libinput-1.14.3
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/libinput/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://wayland.freedesktop.org/libinput/doc/latest/
COMMENT=	Coordinate scaling, relative pointer, acceleration
LICENSE=	mit

USE_TOOLS+=	pkg-config

pre-configure:
	sed -i s/true/false/ ${WRKSRC}/*txt

.include "../../wip/libevdev/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/mtdev/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
