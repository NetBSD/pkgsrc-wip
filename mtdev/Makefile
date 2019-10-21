# $NetBSD$

DISTNAME=	mtdev-1.1.5
CATEGORIES=	devel
MASTER_SITES=	http://bitmath.org/code/mtdev/

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Kernel multitouch event translation
LICENSE=	mit

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=	autoconf automake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
