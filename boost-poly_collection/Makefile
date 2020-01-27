# $NetBSD$

PKGNAME=	boost-poly_collection-20170612
DISTNAME=	develop
CATEGORIES=	devel
MASTER_SITES=	https://github.com/boostorg/poly_collection/archive/
DIST_SUBDIR=	${PKGNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	brook@NetBSD.org
HOMEPAGE=	https://rawgit.com/joaquintides/poly_collection/website/doc/html/index.html
COMMENT=	Containers supporting dynamic polymorphism in C++
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/poly_collection-develop
USE_TOOLS+=	pax

# XXX - remove this or add more to do-install and PLIST
.if !empty(XXX_BUILD_BOOST_POLY_COLLECTION)
USE_LANGUAGES+=	c c++
USE_CMAKE=
CMAKE_INSTALL_PREFIX=	${PREFIX}/include/boost/poly_collection
.include "../../devel/boost-headers/buildlink3.mk"
.else
NO_BUILD=
DEPENDS+=	boost-headers>=1.62.0:../../devel/boost-headers
.endif

INSTALLATION_DIRS+=	include/boost/poly_collection share/examples/boost-poly_collection

do-install:
	cd ${WRKSRC}/include/boost/poly_collection && ${PAX} -rw . ${DESTDIR}${PREFIX}/include/boost/poly_collection
	cd ${WRKSRC}/example && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/boost-poly_collection

.include "../../mk/bsd.pkg.mk"
