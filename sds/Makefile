# $NetBSD$

PKGNAME=	sds-2.0.0.974b5d1
CATEGORIES=	devel
GHCOMMIT=	fb463145c9c245636feb28b5aac0fc897e16f67e
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/sds/archive/}
DIST_SUBDIR=	sds
WRKSRC=		${WRKDIR}/sds-${GHCOMMIT}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/antirez/sds/
COMMENT=	Simple dynamic strings library for C
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	lib include

do-install:
	${INSTALL_LIB} ${WRKSRC}/libsds.so ${DESTDIR}${PREFIX}/lib/libsds.so
	${INSTALL_DATA} ${WRKSRC}/sds.h ${DESTDIR}${PREFIX}/include/sds.h

do-test:
	${WRKSRC}/sds-test

.include "../../mk/bsd.pkg.mk"
