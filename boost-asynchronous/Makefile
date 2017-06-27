# $NetBSD$

PKGNAME=	boost-asynchronous-20170210
DISTNAME=	master
CATEGORIES=	devel
MASTER_SITES=	https://github.com/henry-ch/asynchronous/archive/
DIST_SUBDIR=	${PKGNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	brook@NetBSD.org
HOMEPAGE=	https://github.com/henry-ch/asynchronous/blob/master/libs/asynchronous/doc/asynchronous.html
COMMENT=	An asynchronous C++ library
LICENSE=	boost-license

WRKSRC=		${WRKDIR}/asynchronous-master
USE_TOOLS+=	pax

NO_BUILD=
DEPENDS+=	boost-headers>=1.62.0:../../devel/boost-headers

INSTALLATION_DIRS+=	include/boost/asynchronous share/examples/boost-asynchronous

do-install:
	cd ${WRKSRC}/boost/asynchronous && ${PAX} -rw . ${DESTDIR}${PREFIX}/include/boost/asynchronous
	cd ${WRKSRC}/libs/asynchronous/doc/examples && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/boost-asynchronous

.include "../../mk/bsd.pkg.mk"
