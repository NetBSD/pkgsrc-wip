# $NetBSD$

# PKGNAME=	boost-yap-20170206
PKGNAME=	boost-yap-20170314
DISTNAME=	master
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tzlaine/yap/archive/
DIST_SUBDIR=	${PKGNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	brook@NetBSD.org
HOMEPAGE=	https://github.com/tzlaine/
COMMENT=	A C++14-and-later expression template library
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/yap-master
USE_TOOLS+=	pax

# XXX - remove this or add more to do-install and PLIST
.if !empty(XXX_BUILD_BOOST_YAP)
USE_LANGUAGES+=	c c++
USE_CMAKE=
CMAKE_INSTALL_PREFIX=	${PREFIX}/include/boost/yap
.include "../../devel/boost-headers/buildlink3.mk"
.else
NO_BUILD=
DEPENDS+=	boost-headers>=1.62.0:../../devel/boost-headers
.endif

INSTALLATION_DIRS+=	include/boost/yap share/examples/boost-yap

do-install:
	cd ${WRKSRC}/boost/yap && ${PAX} -rw . ${DESTDIR}${PREFIX}/include/boost/yap
	cd ${WRKSRC}/example && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/boost-yap

.include "../../mk/bsd.pkg.mk"
