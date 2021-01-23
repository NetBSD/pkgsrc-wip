# $NetBSD$

GITHUB_PROJECT=	libstubborn
GITHUB_TAG=	0.1
DISTNAME=	0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=rfht/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rfht/libstubborn/
COMMENT=	library of generic stub functions
LICENSE=	isc

WRKSRC=	${WRKDIR}/libstubborn-0.1

INSTALLATION_DIRS+=	lib

do-install:
	cd ${WRKSRC}; \
	${LN} -sf libstubborn.so.0.0 libstubborn.so
	${INSTALL_DATA} ${WRKSRC}/libstubborn.so* \
		${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
