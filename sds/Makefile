# $NetBSD$

PKGNAME=	sds-2.0.0.974b5d1
CATEGORIES=	devel
GHCOMMIT=	974b5d11f9e17a6659f591bcc07a8bd981acdfd0
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/sds/archive/}
DIST_SUBDIR=	sds
WRKSRC=		${WRKDIR}/sds-${GHCOMMIT}

MAINTAINER=	tpaul@NetBSD.org
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
