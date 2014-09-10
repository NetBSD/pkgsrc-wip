# $NetBSD: options.mk,v 1.8 2014/09/10 06:19:08 makoto Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuradio

PKG_SUPPORTED_OPTIONS+=	atsc
PKG_SUPPORTED_OPTIONS+=	audio-companion
PKG_SUPPORTED_OPTIONS+=	channels
#                       linux only, not checked
PKG_SUPPORTED_OPTIONS+=	comedi
#                       ICE_FOUND= (empty) Ice-3.5.1 at
#                       http://doc.zeroc.com/display/Ice/Home
PKG_SUPPORTED_OPTIONS+=	ctrlport
PKG_SUPPORTED_OPTIONS+=	digital
PKG_SUPPORTED_OPTIONS+=	doxygen
PKG_SUPPORTED_OPTIONS+=	dtvx
PKG_SUPPORTED_OPTIONS+=	fcd
PKG_SUPPORTED_OPTIONS+=	fec
PKG_SUPPORTED_OPTIONS+=	gnuaudio_runtime
PKG_SUPPORTED_OPTIONS+=	noaa
PKG_SUPPORTED_OPTIONS+=	pager
PKG_SUPPORTED_OPTIONS+=	qtgui
#                       (default ?)
PKG_SUPPORTED_OPTIONS+=	runtime
PKG_SUPPORTED_OPTIONS+=	sphinx
PKG_SUPPORTED_OPTIONS+=	trellis
PKG_SUPPORTED_OPTIONS+=	uhd
PKG_SUPPORTED_OPTIONS+=	utils
PKG_SUPPORTED_OPTIONS+=	video-sdl
PKG_SUPPORTED_OPTIONS+=	vocoder
PKG_SUPPORTED_OPTIONS+=	wavelet
PKG_SUPPORTED_OPTIONS+=	wxgui
PKG_SUPPORTED_OPTIONS+=	zeromq

# this 'default' is of upstream definition
PKG_SUPPORTED_OPTIONS+=	default

# next line means really fully available
PKG_SUGGESTED_OPTIONS=	default

.include	"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Matsc)
CMAKE_ARGS+=	-DENABLE_GR_ATSC=True
CMAKE_ARGS+=	-DENABLE_GR_FEC=True
PLIST_SRC+=		${PKGDIR}/PLIST.atsc
PLIST_SRC+=		${PKGDIR}/PLIST.fec
.endif

# in the configure log, it is said gnuradio-companion
.if !empty(PKG_OPTIONS:Maudio-companion)
CMAKE_ARGS+=	-DENABLE_GRC=True
PLIST_SRC+=		${PKGDIR}/PLIST.audio-companion
.include	"../../audio/jack/buildlink3.mk"
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../x11/py-gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mchannels)
CMAKE_ARGS+=	-DENABLE_GR_CHANNELS=True
PLIST_SRC+=		${PKGDIR}/PLIST.channels
.endif

.if !empty(PKG_OPTIONS:Mcomedi)
CMAKE_ARGS+=	-DENABLE_GR_COMEDI=True
PLIST_SRC+=		${PKGDIR}/PLIST.comedi
.endif

# nothing changed:
# .if !empty(PKG_OPTIONS:Mctrlport)
# CMAKE_ARGS+=	-DENABLE_GR_CTRLPORT=True
# PLIST_SRC+=		${PKGDIR}/PLIST.ctrlport
# .endif

.if !empty(PKG_OPTIONS:Mdigital)
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.digital
.endif

.if !empty(PKG_OPTIONS:Mdoxygen)
CMAKE_ARGS+=	-DENABLE_DOXYGEN=True
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

.if !empty(PKG_OPTIONS:Mfcd)
.include	"../../devel/libusb1/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GR_FCD=True
PLIST_SRC+=		${PKGDIR}/PLIST.fcd
.endif

.if !empty(PKG_OPTIONS:Mfec)
CMAKE_ARGS+=	-DENABLE_GR_FEC=True
PLIST_SRC+=		${PKGDIR}/PLIST.fec
.endif

.if !empty(PKG_OPTIONS:Mnoaa)
CMAKE_ARGS+=	-DENABLE_GR_NOAA=True
PLIST_SRC+=		${PKGDIR}/PLIST.noaa
.endif

.if !empty(PKG_OPTIONS:Mpager)
CMAKE_ARGS+=	-DENABLE_GR_PAGER=True
PLIST_SRC+=		${PKGDIR}/PLIST.pager
.endif

.if !empty(PKG_OPTIONS:Mqtgui)
CMAKE_ARGS+=	-DENABLE_QTGUI=True
PLIST_SRC+=		${PKGDIR}/PLIST.qtgui
# following two lines are NOT effective ?
# DEPENDS+=		qt4-[0-9]*:../../x11/qt4/
# .include "../../x11/qt4-libs/buildlink3.mk"
.include	"../../x11/qwt-qt4/buildlink3.mk"
# --   Dependency QT4_FOUND =
# --   Dependency QWT_FOUND = FALSE
.endif

.if !empty(PKG_OPTIONS:Msphinx)
CMAKE_ARGS+=	-DENABLE_SPHINX=True
PLIST_SRC+=		${PKGDIR}/PLIST.sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

.if !empty(PKG_OPTIONS:Mtrellis)
CMAKE_ARGS+=	-DENABLE_GR_TRELLIS=True
CMAKE_ARGS+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.trellis
.endif

.if !empty(PKG_OPTIONS:Muhd)
CMAKE_ARGS+=	-DENABLE_GR_UHD=True
PLIST_SRC+=		${PKGDIR}/PLIST.uhd
.include	"../../ham/uhd/buildlink3.mk"
.include	"../../devel/cppunit/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mruntime)
CMAKE_ARGS+=	-DENABLE_RUNTIME=True
PLIST_SRC+=		${PKGDIR}/PLIST.runtime
.endif

.if !empty(PKG_OPTIONS:Mutils)
CMAKE_ARGS+=	-DENABLE_GR_UTILS=True
PLIST_SRC+=		${PKGDIR}/PLIST.utils
.endif

.if !empty(PKG_OPTIONS:Mvideo-sdl)
CMAKE_ARGS+=	-DENABLE_GR_VIDEO_SDL=True
PLIST_SRC+=		${PKGDIR}/PLIST.video-sdl
.include	"../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvocoder) || !empty(PKG_OPTIONS:Mdefault)
CMAKE_ARGS+=	-DENABLE_GR_VOCODER=True
PLIST_SRC+=		${PKGDIR}/PLIST.vocoder
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.include	"../../audio/gsm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwavelet)
CMAKE_ARGS+=	-DENABLE_GR_WAVELET=True
PLIST_SRC+=		${PKGDIR}/PLIST.wavelet
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwxgui)
CMAKE_ARGS+=	-DENABLE_GR_WXGUI=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True
PLIST_SRC+=		${PKGDIR}/PLIST.wxgui
.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzeromq)
CMAKE_ARGS+=	-DENABLE_GR_ZEROMQ=True
PLIST_SRC+=		${PKGDIR}/PLIST.zeromq
.endif

.if !empty(PKG_OPTIONS:Mdefault)
# please note NOT +=, but = , override everything (but is it default ?)
CMAKE_ARGS=		-DENABLE_DEFAULT=True
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.include	"../../devel/SDL/buildlink3.mk"
.include	"../../devel/cppunit/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
.include	"../../wip/uhd/buildlink3.mk"
.include	"../../x11/py-gtk2/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PLIST_SRC+=		${PKGDIR}/PLIST.atsc
PLIST_SRC+=		${PKGDIR}/PLIST.audio-companion
PLIST_SRC+=		${PKGDIR}/PLIST.channels
PLIST_SRC+=		${PKGDIR}/PLIST.comedi
PLIST_SRC+=		${PKGDIR}/PLIST.ctrlport
PLIST_SRC+=		${PKGDIR}/PLIST.digital
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
PLIST_SRC+=		${PKGDIR}/PLIST.fcd
PLIST_SRC+=		${PKGDIR}/PLIST.fec
PLIST_SRC+=		${PKGDIR}/PLIST.gnuaudio_runtime
PLIST_SRC+=		${PKGDIR}/PLIST.noaa
PLIST_SRC+=		${PKGDIR}/PLIST.pager
PLIST_SRC+=		${PKGDIR}/PLIST.python
PLIST_SRC+=		${PKGDIR}/PLIST.qtgui
PLIST_SRC+=		${PKGDIR}/PLIST.runtime
PLIST_SRC+=		${PKGDIR}/PLIST.sphinx
PLIST_SRC+=		${PKGDIR}/PLIST.trellis
PLIST_SRC+=		${PKGDIR}/PLIST.uhd
PLIST_SRC+=		${PKGDIR}/PLIST.utils
PLIST_SRC+=		${PKGDIR}/PLIST.video-sdl
PLIST_SRC+=		${PKGDIR}/PLIST.vocoder
PLIST_SRC+=		${PKGDIR}/PLIST.wavelet
PLIST_SRC+=		${PKGDIR}/PLIST.wxgui
PLIST_SRC+=		${PKGDIR}/PLIST.zeromq

PLIST_SRC+=		${PKGDIR}/PLIST.default
.endif
