# $NetBSD: Makefile,v 1.1 2014/09/18 00:28:17 makoto Exp $

PKGNAME=	gnuradio-default-${VERSION}
COMMENT=	Full package of gnuradio

# The half of the same target in Nocore.mk
post-install:
# Take care CONF_FILES stuff
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EGDIR}
	${MV}               ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
	                    ${DESTDIR}${PREFIX}/${EGDIR}/

.include	"../../wip/gnuradio-core/Makefile.common"

CONFLICTS=	gnuradio-[0-9]*

CONFLICTS+=	gnuradio-atsc-[0-9]*
CONFLICTS+=	gnuradio-channels-[0-9]*
CONFLICTS+=	gnuradio-companion-[0-9]*
CONFLICTS+=	gnuradio-core-[0-9]*
CONFLICTS+=	gnuradio-ctrlport-[0-9]*

CONFLICTS+=	gnuradio-default-[0-9]*
CONFLICTS+=	gnuradio-digital-[0-9]*
CONFLICTS+=	gnuradio-doxygen-[0-9]*
CONFLICTS+=	gnuradio-dtv-[0-9]*
CONFLICTS+=	gnuradio-fcd-[0-9]*

CONFLICTS+=	gnuradio-fec-[0-9]*
CONFLICTS+=	gnuradio-noaa-[0-9]*
CONFLICTS+=	gnuradio-pager-[0-9]*
CONFLICTS+=	gnuradio-qtgui-[0-9]*
CONFLICTS+=	gnuradio-trellis-[0-9]*

CONFLICTS+=	gnuradio-uhd-[0-9]*
CONFLICTS+=	gnuradio-utils-[0-9]*
CONFLICTS+=	gnuradio-video-sdl-[0-9]*
CONFLICTS+=	gnuradio-vocoder-[0-9]*
CONFLICTS+=	gnuradio-wavelet-[0-9]*

CONFLICTS+=	gnuradio-wxgui-[0-9]*

CONF_FILES+=	${EGDIR}/gr-qtgui.conf		gr-qtgui.conf
CONF_FILES+=	${EGDIR}/modtool.conf		modtool.conf
CONF_FILES+=	${EGDIR}/gr-wxgui.conf		gr-wxgui.conf
CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	gnuradio-runtime.conf
.if 0
# partly duplicate with core/Makefile.common
CONF_FILES+=	${EGDIR}/gr-audio-alsa.conf	gr-audio-alsa.conf
CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	gr-audio-jack.conf
CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	gr-audio-oss.conf
CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf gr-audio-portaudio.conf
CONF_FILES+=	${EGDIR}/gr-audio.conf		gr-audio.conf
.endif
# --------       R E S E T    H E R E  -------------
CMAKE_ARGS+=	-DENABLE_DEFAULT=True
.if 0
# set default as minimum (and adding at options.mk)
# See  http://gnuradio.org/redmine/projects/gnuradio/wiki/BuildGuide
#      http://gnuradio.org/redmine/projects/gnuradio/wiki/CygwinInstallMain

CMAKE_ARGS+=	-DENABLE_GNURADIO_RUNTIME=True

#MAKE_ARGS+=	-DENABLE_ZEROMQ=Off

# Default (for pkgsrc) setting
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
CMAKE_ARGS+=	-DUHD_INCLUDE_DIRS=${PREFIX}/include/uhd/usrp

CMAKE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include

CMAKE_ARG_PATH=		../
.endif

# .include "../../x11/qt4-libs/buildlink3.mk"
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/gsm/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"

.include	"../../devel/SDL/buildlink3.mk"
.include	"../../devel/cppunit/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
# gr-zeromq/lib/pub_sink_impl.h:27:19: fatal error: zmq.hpp: No such file..
#include	"../../net/zeromq/buildlink3.mk"

.include	"../../x11/py-gtk2/buildlink3.mk"
.include	"../../x11/py-qt4/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"
.include	"../../x11/qt4-libs/buildlink3.mk"
.include	"../../x11/qwt-qt4/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
