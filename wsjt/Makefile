# $NetBSD$

DISTNAME=	wsjtx-2.3.0
CATEGORIES=	ham
MASTER_SITES=	https://physics.princeton.edu/pulsar/k1jt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://physics.princeton.edu/pulsar/k1jt/
COMMENT=	Well known in the amateur radio WSJT
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

DEPENDS+=	qt5-qttranslations-[0-9]*:../../x11/qt5-qttranslations

CMAKE_ARGS+=	-DNVTT_SHARED=ON
CMAKE_ARGS+=	-D CMAKE_INSTALL_PREFIX=${DESTDIR}${PREFIX}
CMAKE_ARGS+=	-DWSJT_SKIP_MANPAGES=ON
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX}/qt5
CMAKE_ARGS+=	-DWSJT_GENERATE_DOCS=OFF

#LDFLAGS+=	-L${PREFIX}/lib -lusb-1.0
#MAKE_ENV+=	LIBUSB_FLAGS='-L${PREFIX}/lib -lusb-1.0'

# debug only (checking log)
MAKE_JOBS_SAFE=	no

.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
#include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
#BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=4.1
#.include "../../ham/hamlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
