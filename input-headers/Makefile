# $NetBSD$

DISTNAME=	input-headers-1.26.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sizeofvoid/}
GITHUB_PROJECT=	libopeninput
GITHUB_TAG=	cf9699e76e41bf1b824c3820d06d36a2b0fbb8c1

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/sizeofvoid/libopeninput/tree/build-on-openbsd/
COMMENT=	Input headers from libopeninpu
LICENSE=	mit

USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/libopeninput-${GITHUB_TAG}

INSTALLATION_DIRS+=	include/linux

do-configure:

do-build:

do-install:
	cd ${WRKSRC}/include/linux && \
		${FIND} . -type f -name "*.h" -print | pax -rw -pmp ${DESTDIR}${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
