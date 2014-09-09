# $NetBSD: Makefile,v 1.13 2014/09/09 07:48:44 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Runtime system and DSP blocks for GNU Radio

LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.SunOS+=		-lboost_system

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 # not yet ported as of 3.3.0
.include	"../../wip/gnuradio/Makefile.common"

BUILD_DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

# gnuradio-companion wants:
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/

USE_TOOLS=		perl gmake cmake pkg-config
USE_LANGUAGES+=         c c++
USE_LIBTOOL=            yes
USE_CMAKE=		yes

#CONF_FILES= ${ETCDIR}/gnuaudio-runtime.conf hoge
# REPLACE_PYTHON is some 600 files
.include	"files/REPLACE_PYTHON"

PLIST_SRC=	${PKGDIR}/PLIST

# See  http://gnuradio.org/redmine/projects/gnuradio/wiki/BuildGuide
#      http://gnuradio.org/redmine/projects/gnuradio/wiki/CygwinInstallMain
CONFIGURE_DIRS=		build

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH=${PREFIX}/include/portaudio2
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH=${PREFIX}/lib/portaudio2
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib:${PREFIX}/lib/portaudio2
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE
CMAKE_ARGS+=	-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0

CMAKE_ARGS+=	-DGR_LIBRARY_DIR=${DESTDIR}${PREFIX}/lib
CMAKE_ARGS+=	-DGR_PREFSDIR=${DESTDIR}${PREFIX}/share/

CMAKE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL
CMAKE_ARGS+=	-DUHD_LIBRARIES=${PREFIX}/lib/libuhd.so
CMAKE_ARGS+=	-DUHD_INCLUDE_DIRS=${PREFIX}/include

# set default as minimum (and adding at options.mk)
CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_PYTHON=True
CMAKE_ARGS+=	-DENABLE_GNURADIO_COMPANION=True
CMAKE_ARGS+=	-DENABLE_VOLK=True
CMAKE_ARGS+=	-DENABLE_GNURADIO_RUNTIME=True
CMAKE_ARGS+=	-DENABLE_GR_BLOCKS=True
CMAKE_ARGS+=	-DENABLE_GR_FFT=True
CMAKE_ARGS+=	-DENABLE_GR_FILTER=True
CMAKE_ARGS+=	-DENABLE_GR_ANALOG=True
CMAKE_ARGS+=	-DENABLE_GR_AUDIO=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True
CMAKE_ARGS+=	-DENABLE_GNURADIO_RUNTIME=True

CMAKE_ARG_PATH=		../

.include	"../../lang/python/extension.mk"
.include	"../../lang/python/application.mk"
.include	"options.mk"

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	(${MKDIR} ${WRKSRC}/build;)

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
#	(cd ${WRKSRC}/build; env DESTDIR=${DESTDIR} ${GMAKE} package)
	(cd ${WRKSRC}/build; ${GMAKE} DESTDIR=${DESTDIR} install)

.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.include	"../../audio/portaudio-devel/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"
.include	"../../devel/swig2/buildlink3.mk"
.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
#BUILDLINK_DEPMETHOD.guile=	build
#.include	"../../lang/guile/buildlink3.mk"
.include	"../../math/fftwf/buildlink3.mk"
.include	"../../math/py-numpy/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
