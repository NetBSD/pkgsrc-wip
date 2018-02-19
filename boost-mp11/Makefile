# $NetBSD$

GITHUB_PROJECT=	mp11
DISTNAME=	develop
PKGNAME=	${GITHUB_PROJECT}-20170622
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pdimov/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pdimov/mp11/
COMMENT=	A C++11 metaprogramming library
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/mp11-develop
USE_TOOLS+=	pax
NO_BUILD=

INSTALLATION_DIRS+=	include/boost

do-install:
	cd ${WRKSRC}/include/boost && ${PAX} -rw . ${DESTDIR}${PREFIX}/include/boost

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
