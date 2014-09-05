# $NetBSD: Makefile,v 1.9 2014/09/05 16:36:11 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Runtime system and DSP blocks for GNU Radio

LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.SunOS+=		-lboost_system

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 # not yet ported as of 3.3.0
.include "../../wip/gnuradio/Makefile.common"

BUILD_DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

# gnuradio-companion wants:
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/

USE_TOOLS+=             perl gmake cmake pkg-config
USE_LANGUAGES+=         c c++
USE_LIBTOOL=            yes

# set default as minimum (and adding at options.mk)
GR_ENABLE_LIST=	\
	-DENABLE_DEFAULT=False \
	-DENABLE_VOLK=True \
	-DENABLE_GNURADIO_RUNTIME=True \
	-DENABLE_GR_BLOCKS=True \
	-DENABLE_GR_FFT=True \
	-DENABLE_GR_FILTER=True \
	-DENABLE_GR_ANALOG=True \
	-DENABLE_GR_AUDIO=True \
	-DENABLE_PYTHON=True \
	-DENABLE_GNURADIO_RUNTIME=True \

#CONF_FILES= ${ETCDIR}/gnuaudio-runtime.conf hoge
# REPLACE_PYTHON is some 600 files
.include "files/REPLACE_PYTHON"

PLIST_SRC=	${PKGDIR}/PLIST

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# See  http://gnuradio.org/redmine/projects/gnuradio/wiki/BuildGuide
#      http://gnuradio.org/redmine/projects/gnuradio/wiki/CygwinInstallMain
do-configure:
	(  ${MKDIR} ${WRKSRC}/build; \
	         cd ${WRKSRC}/build; \
	cmake \
	-Wno-dev \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INCLUDE_PATH=${PREFIX}/include/portaudio2 \
	-DCMAKE_LIBRARY_PATH=${PREFIX}/lib/portaudio2 \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib:${PREFIX}/lib/portaudio2 \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0 \
	-DGR_LIBRARY_DIR=${DESTDIR}${PREFIX}/lib \
	-DGR_PREFSDIR=${DESTDIR}${PREFIX}/share/ \
	${GR_ENABLE_LIST} \
	../; \
	)

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
#	(cd ${WRKSRC}/build; env DESTDIR=${DESTDIR} ${GMAKE} package)
	(cd ${WRKSRC}/build; ${GMAKE} DESTDIR=${DESTDIR} install)

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
#.include "../../devel/libusb1/buildlink3.mk"
#.include "../../devel/swig2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/cppunit/buildlink3.mk"
#BUILDLINK_DEPMETHOD.guile=	build
#.include "../../lang/guile/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
#.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
