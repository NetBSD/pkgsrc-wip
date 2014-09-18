# $NetBSD: Makefile,v 1.2 2014/09/18 03:43:28 makoto Exp $

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

BUILD_DEPENDS+=    ${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=       ${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/

# --------       R E S E T    H E R E  -------------
CMAKE_ARGS+=	-DENABLE_DEFAULT=True

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
