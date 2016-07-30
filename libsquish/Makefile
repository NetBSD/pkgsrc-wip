# $NetBSD$

DISTNAME=	libsquish-1.13
CATEGORIES=	graphics
MASTER_SITES=	https://sourceforge.net/projects/libsquish/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libsquish/files/
COMMENT=	Open source DXT compression library
LICENSE=	mit

EXTRACT_DIR=	${WRKDIR}/${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
