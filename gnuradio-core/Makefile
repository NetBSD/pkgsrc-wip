# $NetBSD: Makefile,v 1.4 2014/09/01 07:22:21 makoto Exp $

PKGNAME=	gnuradio-core-${VERSION}
COMMENT=	Runtime system and DSP blocks for GNU Radio

LDFLAGS.DragonFly+=	-lboost_system
LDFLAGS.SunOS+=		-lboost_system

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 # not yet ported as of 3.3.0
.include "../../wip/gnuradio/Makefile.common"

USE_TOOLS+=             perl gmake cmake pkg-config
USE_LANGUAGES+=         c c++
USE_LIBTOOL=            yes
USE_CMAKE=              yes

# There is an unresolved build failure, where -R for /usr/pkg/lib does
# not precede /usr/X11R7/lib, and on a netbsd-5 system with base xorg,
# an old version of pixman is found by the pkgsrc cairo.  The root
# cause (aside from having two pixman versions installed) is ad hoc -L
# usage in Makefile.am, without matching -R.

do-configure:
	(cd ${WRKSRC}; \
	${MKDIR} build; \
	cd build; \
	cmake \
	-Wno-dev \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INCLUDE_PATH=${PREFIX}/include/portaudio2 \
	-DCMAKE_LIBRARY_PATH=${PREFIX}/lib/portaudio2 \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0 \
	../; \
	)

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
	(cd ${WRKSRC}/build; env DESTDIR=${DESTDIR} ${GMAKE} install)

post-install:
	(cd ${WRKSRC}/build)

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/py-cheetah/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
BUILDLINK_DEPMETHOD.guile=	build
.include "../../lang/guile/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
