# $NetBSD: Makefile,v 1.107 2023/04/07 12:58:01 mef Exp $

VERSION=	3.10.6.0
PKGNAME=	gnuradio-monolithic-${VERSION}
COMMENT=	GNU Software Defined Radio Monolithic version

DISTNAME?=	gnuradio-${VERSION}
CATEGORIES+=	ham
#MASTER_SITES=	http://s3-dist.gnuradio.org/
#MASTER_SITES+=	http://gnuradio.org/releases/gnuradio/
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnuradio/}
GITHUB_PROJECT=	gnuradio
GITHUB_TAG=	v${VERSION}

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://www.gnu.org/software/gnuradio/
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake perl pkg-config

GCC_REQD+=	8

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099915
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygccxml-[0-9]*:../../textproc/py-pygccxml
# for companion
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

# see CMakeLists.txt GR_PYTHON_MIN_VERSION
PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-scipy

# three digit version number for shared library ex 3.10.2.0 -> 3.10.2
PKGVER_MICRO=	${PKGVERSION_NOREV:C/([0-9]+)\.([0-9]+)\.([0-9]+)\.([0-9]+)/\1.\2.\3/}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
# avoid using the name PKGVERSION in variable, see Nocore.mk
PLIST_SUBST+=	PKGVER_MICRO=${PKGVER_MICRO}
PY_PATCHPLIST=	yes

CONFIGURE_DIRS=	build

EGDIR=			share/gnuradio/examples
PKG_SYSCONFSUBDIR=	gnuradio/conf.d

CXXFLAGS+=		-pthread
CFLAGS+=		-pthread
LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.NetBSD+=	-lrt
LDFLAGS.SunOS+=		-lboost_system
CXXFLAGS.SunOS+=	-pthreads

INSTALLATION_DIRS+=	${EGDIR}

# --------       R E S E T  CMAKE_CONFIGURE_ARGS  H E R E  -------------
CMAKE_CONFIGURE_ARGS=

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GNURADIO_RUNTIME=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_ANALOG=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_AUDIO=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_BLOCKS=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FFT=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_FILTER=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PYTHON=ON

CMAKE_CONFIGURE_ARGS+=	-DLIB_SUFFIX=""

# Default setting (for pkgsrc)
CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INCLUDE_PATH=${PREFIX}/include/portaudio2
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_LIBRARY_PATH=${PREFIX}/lib/portaudio2
#MAKE_ARGS+=	-DCMAKE_MAN_PATH=${PREFIX}/man
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib:${PREFIX}/lib/portaudio2
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE
CMAKE_CONFIGURE_ARGS+=	-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

CMAKE_CONFIGURE_ARGS+=	-DGR_LIBRARY_DIR=${PREFIX}/lib
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib:${PREFIX}/lib/portaudio2
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE
CMAKE_CONFIGURE_ARGS+=	-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

CMAKE_CONFIGURE_ARGS+=	-DGR_LIBRARY_DIR=${PREFIX}/lib
CMAKE_CONFIGURE_ARGS+=	-DGR_PREFSDIR=${PREFIX}/share/gnuradio/examples/

# adhoc setup not to pick non default version (say python3.6)
# at configure
#CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PREFIX}/bin/python${PYVERSSUFFIX}

CMAKE_CONFIGURE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include
CMAKE_ARG_PATH=	../

.include "options.mk"

# disable/enable ALSA, see also patches/patch-gr-audio_lib_CMakeLists.txt
SUBST_CLASSES+=		alsa
SUBST_MESSAGE.alsa=	Arrange the patched line depepending on alsa is in PKG_OPTIONS or not
SUBST_FILES.alsa+=	gr-audio/lib/CMakeLists.txt
## The value of ${ALSA_ENABLED} is either '#' or '' by options.mk.
SUBST_SED.alsa=		-e 's,@@ALSA@@,${ALSA_ENABLED},'
SUBST_STAGE.alsa=	pre-configure

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Substitute PREFIX
SUBST_FILES.prefix=	gnuradio-runtime/lib/constants.cc.in
SUBST_VARS.prefix=	PREFIX

REPLACE_PYTHON=		*/*.py */*/*.py */*/*/*.py */*/*/*/*.py */*/*/*/*/*.py \
			*/*/*/*/*/*/*.py */*/*/*/*/*/*/*.py */*/*/*/*/*/*/*/*.py

pre-configure:
	${MKDIR} ${WRKSRC}/build

do-install:
	cd ${WRKSRC}/${BUILD_DIRS} && ${GMAKE} DESTDIR=${DESTDIR} install

.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-pybind11+=	${PYPKGPREFIX}-pybind11>=2.6.0
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
# FIXME should be optional
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/volk/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

TOOL_DEPENDS+=	tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar

#CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
#CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
#CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
#CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_VIDEO_SDL=ON
CMAKE_CONFIGURE_ARGS+=	-DSDL_INCLUDE_DIR=${PREFIX}/include/SDL

# Take care CONF_FILES stuff (The same code in Nocore.mk)
#post-install:
#	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
#	      ${DESTDIR}${PREFIX}/${EGDIR}/

.include "../../ham/codec2/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
