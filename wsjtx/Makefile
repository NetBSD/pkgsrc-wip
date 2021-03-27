# $NetBSD$

DISTNAME=	wsjtx-2.3.0
CATEGORIES=	ham
MASTER_SITES=	https://physics.princeton.edu/pulsar/k1jt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://physics.princeton.edu/pulsar/k1jt/
COMMENT=	Weak Signal Communication by Joe Talor (K1JT)
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
CMAKE_ARGS+=	-DLDFLAGS='-lusb-1.0 -L${PREFIX}/lib'
CMAKE_ARGS+=	-DLDFLAGS=-'Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib'
CMAKE_ARGS+=	-DLIBUSB_CFLAGS='-I ${PREFIX}/include/libusb-1.0 -lusb-1.0 -L${PREFIX}/lib'
CMAKE_ARGS+=	-DLIBUSB_LIBS=-Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib
CMAKE_ARGS+=	-DLIBS=-Wl,-rpath-link=-lusb-1.0 -L${PREFIX}/lib

#IBUSB_CFLAGS+=	-lusb-1.0 -L${PREFIX}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}=-lusb-1.0 -L${PREFIX}/lib
#MAKE_ENV+=	LIBUSB_FLAGS='-lusb-1.0 -L${PREFIX}/lib'

# debug only (checking log)
MAKE_JOBS_SAFE=	no

# hamlib-prefix/src/hamlib/configure.ac
SUBST_CLASSES+=		hamlib
SUBST_FILES.hamlib=	hamlib.patch
SUBST_STAGE.hamlib=	pre-configure
SUBST_MESSAGE.hamlib=	fix PREFIX inside patch
SUBST_VARS.hamlib=	PREFIX


.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=4.1
.include "../../ham/hamlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
