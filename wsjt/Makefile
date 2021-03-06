# $NetBSD$

DISTNAME=	wsjtx-2.3.0
CATEGORIES=	ham
MASTER_SITES=	https://physics.princeton.edu/pulsar/k1jt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://physics.princeton.edu/pulsar/k1jt/
COMMENT=	Well known in the amateur radio WSJT
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++ fortran

DEPENDS+=	qt5-qttranslations-[0-9]*:../../x11/qt5-qttranslations

#CMAKE_ARGS+=    -DNVTT_SHARED=ON
do-configure:
	(cd ${WRKSRC}; \
	mkdir build;\
	cd    build;\
	cmake \
 	-D CMAKE_INSTALL_PREFIX=${DESTDIR}${PREFIX} \
	-DWSJT_SKIP_MANPAGES=ON \
	-DCMAKE_PREFIX_PATH=${PREFIX}/qt5 \
	-DWSJT_GENERATE_DOCS=OFF ../../wsjtx-2.3.0 \
	)

do-build:
	(cd ${WRKSRC}/build; cmake --build . )

.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
