# $NetBSD$

DISTNAME=	libevdev-1.9.1
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/libevdev/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://www.freedesktop.org/software/libevdev/doc/latest/
COMMENT=	Keyboard and mouse events, capability bits
LICENSE=	mit

ONLY_FOR_PLATFORM=	Linux-*-*
MESON_ARGS+=		-Ddocumentation=disabled -Dtests=disabled

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
