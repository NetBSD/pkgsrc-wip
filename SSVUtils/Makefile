# $NetBSD$
#

# use date of commit as has no version only a tag

DISTNAME=	SSVUtils
PKGNAME=	${DISTNAME}-20130714
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	c8190f843ab5bdfcff99e92aec7421c413c887e3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVUtils
COMMENT=	C++14 multi-purpose utility library that only depends on the STL
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/

.include "../../mk/bsd.pkg.mk"
