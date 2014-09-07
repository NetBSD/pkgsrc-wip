# $NetBSD: options.mk,v 1.6 2014/09/07 10:50:07 makoto Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuradio-core
PKG_SUPPORTED_OPTIONS=	ctrlport digital doxygen qtgui runtime utils wxgui
PKG_SUPPORTED_OPTIONS+=	fec atsc comedi channels noaa pager trellis uhd
PKG_SUPPORTED_OPTIONS+=	fcd wavelet vocoder video-sdl audio-companion
PKG_SUPPORTED_OPTIONS+=	gnuaudio_runtime sphinx
PKG_SUPPORTED_OPTIONS+=	default

# lists checked combination here, having # in leftmost column has a problem.
# To judge the result quickly, see the log after just 'make configure'
# (but more to 'make package' for real completion)

PKG_SUGGESTED_OPTIONS=	ctrlport	 doxygen		     wxgui
PKG_SUGGESTED_OPTIONS=		 digital	 
PKG_SUGGESTED_OPTIONS=						     wxgui
# not wholly checked yet
# linux only, not checked
#KG_SUGGESTED_OPTIONS=		 comedi
# ICE_FOUND= (empty) Ice-3.5.1 at http://doc.zeroc.com/display/Ice/Home
#KG_SUGGESTED_OPTIONS=	ctrlport
# packaged:
PKG_SUGGESTED_OPTIONS=	digital fec wxgui
PKG_SUGGESTED_OPTIONS=	digital fec wxgui			     uhd
PKG_SUGGESTED_OPTIONS=	fec
PKG_SUGGESTED_OPTIONS=	    atsc
PKG_SUGGESTED_OPTIONS=			 channels
PKG_SUGGESTED_OPTIONS=				  noaa
PKG_SUGGESTED_OPTIONS=				       pager
PKG_SUGGESTED_OPTIONS=					     trellis
PKG_SUGGESTED_OPTIONS=						     uhd
PKG_SUGGESTED_OPTIONS=	fcd
PKG_SUGGESTED_OPTIONS=	     wavelet
PKG_SUGGESTED_OPTIONS=			vocoder
PKG_SUGGESTED_OPTIONS=					      utils
PKG_SUGGESTED_OPTIONS=						     wxgui
#KG_SUGGESTED_OPTIONS=				qtgui
# no effect now (default ?)
#PKG_SUGGESTED_OPTIONS=					      runtime
PKG_SUGGESTED_OPTIONS=	doxygen
PKG_SUGGESTED_OPTIONS=				video-sdl
PKG_SUGGESTED_OPTIONS=					     audio-companion
# this 'default' is of upstream definition
PKG_SUGGESTED_OPTIONS=	default

.include	"../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Matsc)
GR_ENABLE_LIST+=	-DENABLE_GR_ATSC=True
GR_ENABLE_LIST+=	-DENABLE_GR_FEC=True
PLIST_SRC+=		${PKGDIR}/PLIST.atsc
PLIST_SRC+=		${PKGDIR}/PLIST.fec
.endif

# in the configure log, it is said gnuradio-companion
.if !empty(PKG_OPTIONS:Maudio-companion)
GR_ENABLE_LIST+=	-DENABLE_GRC=True
PLIST_SRC+=		${PKGDIR}/PLIST.audio-companion
.include	"../../audio/jack/buildlink3.mk"
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../x11/py-gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mchannels)
GR_ENABLE_LIST+=	-DENABLE_GR_CHANNELS=True
PLIST_SRC+=		${PKGDIR}/PLIST.channels
.endif

.if !empty(PKG_OPTIONS:Mcomedi)
GR_ENABLE_LIST+=	-DENABLE_GR_COMEDI=True
PLIST_SRC+=		${PKGDIR}/PLIST.comedi
.endif

# nothing changed:
# .if !empty(PKG_OPTIONS:Mctrlport)
# GR_ENABLE_LIST+=	-DENABLE_GR_CTRLPORT=True
# PLIST_SRC+=		${PKGDIR}/PLIST.ctrlport
# .endif

.if !empty(PKG_OPTIONS:Mdigital)
GR_ENABLE_LIST+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.digital
.endif

.if !empty(PKG_OPTIONS:Mdoxygen)
GR_ENABLE_LIST+=	-DENABLE_DOXYGEN=True
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

.if !empty(PKG_OPTIONS:Mfcd)
.include	"../../devel/libusb1/buildlink3.mk"
GR_ENABLE_LIST+=	-DENABLE_GR_FCD=True
PLIST_SRC+=		${PKGDIR}/PLIST.fcd
.endif

.if !empty(PKG_OPTIONS:Mfec)
GR_ENABLE_LIST+=	-DENABLE_GR_FEC=True
PLIST_SRC+=		${PKGDIR}/PLIST.fec
.endif

.if !empty(PKG_OPTIONS:Mnoaa)
GR_ENABLE_LIST+=	-DENABLE_GR_NOAA=True
PLIST_SRC+=		${PKGDIR}/PLIST.noaa
.endif

.if !empty(PKG_OPTIONS:Mpager)
GR_ENABLE_LIST+=	-DENABLE_GR_PAGER=True
PLIST_SRC+=		${PKGDIR}/PLIST.pager
.endif

.if !empty(PKG_OPTIONS:Mqtgui)
GR_ENABLE_LIST+=	-DENABLE_QTGUI=True
PLIST_SRC+=		${PKGDIR}/PLIST.qtgui
# following two lines are NOT effective ?
# DEPENDS+=		qt4-[0-9]*:../../x11/qt4/
# .include "../../x11/qt4-libs/buildlink3.mk"
.include	"../../x11/qwt-qt4/buildlink3.mk"
# --   Dependency QT4_FOUND =
# --   Dependency QWT_FOUND = FALSE
.endif

.if !empty(PKG_OPTIONS:Msphinx)
GR_ENABLE_LIST+=	-DENABLE_SPHINX=True
PLIST_SRC+=		${PKGDIR}/PLIST.sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
.endif

.if !empty(PKG_OPTIONS:Mtrellis)
GR_ENABLE_LIST+=	-DENABLE_GR_TRELLIS=True
GR_ENABLE_LIST+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.trellis
.endif

.if !empty(PKG_OPTIONS:Muhd)
GR_ENABLE_LIST+=	-DENABLE_GR_UHD=True
PLIST_SRC+=		${PKGDIR}/PLIST.uhd
.include	"../../wip/uhd/buildlink3.mk"
.include	"../../devel/cppunit/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mruntime)
GR_ENABLE_LIST+=	-DENABLE_RUNTIME=True
PLIST_SRC+=		${PKGDIR}/PLIST.runtime
.endif

.if !empty(PKG_OPTIONS:Mutils)
GR_ENABLE_LIST+=	-DENABLE_GR_UTILS=True
PLIST_SRC+=		${PKGDIR}/PLIST.utils
.endif

.if !empty(PKG_OPTIONS:Mvideo-sdl)
GR_ENABLE_LIST+=	-DENABLE_GR_VIDEO_SDL=True
PLIST_SRC+=		${PKGDIR}/PLIST.video-sdl
.include	"../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvocoder)
GR_ENABLE_LIST+=	-DENABLE_GR_VOCODER=True
PLIST_SRC+=		${PKGDIR}/PLIST.vocoder
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwavelet)
GR_ENABLE_LIST+=	-DENABLE_GR_WAVELET=True
PLIST_SRC+=		${PKGDIR}/PLIST.wavelet
.include	"../../audio/alsa-lib/buildlink3.mk"
.include	"../../audio/jack/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwxgui)
GR_ENABLE_LIST+=	-DENABLE_GR_WXGUI=True
GR_ENABLE_LIST+=	-DENABLE_PYTHON=True
PLIST_SRC+=		${PKGDIR}/PLIST.wxgui
.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdefault)
# please note NOT +=, but =
GR_ENABLE_LIST=		-DENABLE_DEFAULT=True
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
PLIST_SRC+=		${PKGDIR}/PLIST.noaa
PLIST_SRC+=		${PKGDIR}/PLIST.pager
PLIST_SRC+=		${PKGDIR}/PLIST.python
PLIST_SRC+=		${PKGDIR}/PLIST.qtgui
PLIST_SRC+=		${PKGDIR}/PLIST.runtime
PLIST_SRC+=		${PKGDIR}/PLIST.trellis
PLIST_SRC+=		${PKGDIR}/PLIST.uhd
PLIST_SRC+=		${PKGDIR}/PLIST.utils
PLIST_SRC+=		${PKGDIR}/PLIST.video-sdl
PLIST_SRC+=		${PKGDIR}/PLIST.vocoder
PLIST_SRC+=		${PKGDIR}/PLIST.wavelet
PLIST_SRC+=		${PKGDIR}/PLIST.wxgui
PLIST_SRC+=		${PKGDIR}/PLIST.default
.endif
