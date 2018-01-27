# $NetBSD: Makefile,v 1.9 2015/07/13 15:11:02 thomasklausner Exp $

DISTNAME=	mapnik-v3.0.12
PKGNAME=	${DISTNAME:S/-v/-/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=mapnik/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mapnik.org/
COMMENT=	Toolkit for mapping applications

NO_CONFIGURE=		yes
BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
DEPENDS+=		dejavu-ttf>=2.19:../../fonts/dejavu-ttf
USE_LANGUAGES=		c c++

PTHREAD_AUTO_VARS=	yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
SCONS_ENV=		PREFIX=${PREFIX} DESTDIR=${DESTDIR} \
			FREETYPE_CONFIG=${PREFIX}/bin/freetype-config \
			PROJ_INCLUDES=${PREFIX}/include \
			PROJ_LIBS=${PREFIX}/lib

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons ${SCONS_ENV}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PREFIX}/bin/scons ${SCONS_ENV} install

.include "../../devel/py-boost/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
