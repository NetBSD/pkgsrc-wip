# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:27 thomasklausner Exp $
#

DISTNAME=	mapnik-0.4.0
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/mapnik/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mapnik.org/
COMMENT=	Toolkit for mapping applications

NO_CONFIGURE=		yes
BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
DEPENDS+=		dejavu-ttf>=2.19:../../fonts/dejavu-ttf
USE_LANGUAGES=		c++

PKG_DESTDIR_SUPPORT=	user-destdir
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

.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
