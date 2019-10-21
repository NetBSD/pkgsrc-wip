# $NetBSD$

DISTNAME=	libevdev-1.8.0
CATEGORIES=	devel
MASTER_SITES=	https://www.freedesktop.org/software/libevdev/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://www.freedesktop.org/software/libevdev/doc/latest/
COMMENT=	Keyboard and mouse events, capability bits
LICENSE=	mit

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=	autoconf automake gmake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
