# $NetBSD: options.mk,v 1.1 2014/09/04 16:35:39 makoto Exp $
### Set options
PKG_OPTIONS_VAR=        PKG_OPTIONS.gnuradio-core
PKG_SUPPORTED_OPTIONS=  ctrlport digital doxygen qtgui runtime utils wxgui
PKG_SUPPORTED_OPTIONS+= fec atsc comedi channels noaa pager trellis uhd
PKG_SUPPORTED_OPTIONS+= fcd wavelet vocoder video-sdl audio-companion

# lists checked combination, having # in leftmost column has a problem
# To judge the result quickly, see the log after just 'make configure'
# (but more to 'make package' completes)

PKG_SUGGESTED_OPTIONS=  ctrlport 	 doxygen  	             wxgui
#KG_SUGGESTED_OPTIONS=	ctrlport                                              
#KG_SUGGESTED_OPTIONS= 				 	      utils
#KG_SUGGESTED_OPTIONS= 				qtgui
PKG_SUGGESTED_OPTIONS=           digital	 
PKG_SUGGESTED_OPTIONS=  	 	          	             wxgui
# no effect now (default ?)
PKG_SUGGESTED_OPTIONS= 				      runtime
PKG_SUGGESTED_OPTIONS=  fec
# not wholly checked yet
PKG_SUGGESTED_OPTIONS=      atsc
PKG_SUGGESTED_OPTIONS=                   channels
PKG_SUGGESTED_OPTIONS=                            noaa
PKG_SUGGESTED_OPTIONS=                                 pager
PKG_SUGGESTED_OPTIONS=                                       trellis
#PKG_SUGGESTED_OPTIONS=                                               uhd
# linux only, not checked
#KG_SUGGESTED_OPTIONS=           comedi
PKG_SUGGESTED_OPTIONS=  digital fec wxgui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Matsc)
GR_ENABLE_LIST+=	-DENABLE_GR_ATSC=True
GR_ENABLE_LIST+=	-DENABLE_GR_FEC=True
PLIST_SRC+=		${PKGDIR}/PLIST.atsc
.endif

.if !empty(PKG_OPTIONS:Mchannels)
GR_ENABLE_LIST+=	-DENABLE_GR_CHANNELS=True
PLIST_SRC+=		${PKGDIR}/PLIST.channels
.endif

.if !empty(PKG_OPTIONS:Mcomedi)
GR_ENABLE_LIST+=	-DENABLE_GR_COMEDI=True
PLIST_SRC+=		${PKGDIR}/PLIST.comedi
.endif

.if !empty(PKG_OPTIONS:Mctrlport)
GR_ENABLE_LIST+=	-DENABLE_GR_CTRLPORT=True
PLIST_SRC+=		${PKGDIR}/PLIST.ctrlport
.endif

.if !empty(PKG_OPTIONS:Mdigital)
GR_ENABLE_LIST+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.digital
.endif

.if !empty(PKG_OPTIONS:Mdoxygen)
GR_ENABLE_LIST+=	-DENABLE_GR_DOXYGEN=True
PLIST_SRC+=		${PKGDIR}/PLIST.doxygen
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
.include "../../x11/qwt-qt4/buildlink3.mk"
# --   Dependency QT4_FOUND =
# --   Dependency QWT_FOUND = FALSE
.endif

.if !empty(PKG_OPTIONS:Mtrellis)
GR_ENABLE_LIST+=	-DENABLE_GR_TRELLIS=True
GR_ENABLE_LIST+=	-DENABLE_GR_DIGITAL=True
PLIST_SRC+=		${PKGDIR}/PLIST.trellis
.endif

.if !empty(PKG_OPTIONS:Mctrlport)
GR_ENABLE_LIST+=	-DENABLE_GR_CTRLPORT=True
PLIST_SRC+=		${PKGDIR}/PLIST.ctrlport
.endif

.if !empty(PKG_OPTIONS:Muhd)
GR_ENABLE_LIST+=	-DENABLE_GR_UHD=True
PLIST_SRC+=		${PKGDIR}/PLIST.uhd
DEPENDS+=		uhd-[0-9]*:../../wip/uhd-git
.endif

#.if !empty(PKG_OPTIONS:Mruntime)
# GR_ENABLE_LIST+=	-DENABLE_RUNTIME=True
# PLIST_SRC+=		${PKGDIR}/PLIST.runtime
#.endif

.if !empty(PKG_OPTIONS:Mutils)
GR_ENABLE_LIST+=	-DENABLE_GR_UTILS=True
PLIST_SRC+=		${PKGDIR}/PLIST.utils
.endif

.if !empty(PKG_OPTIONS:Mwxgui)
GR_ENABLE_LIST+=	-DENABLE_GR_WXGUI=True
GR_ENABLE_LIST+=	-DENABLE_PYTHON=True
PLIST_SRC+=		${PKGDIR}/PLIST.wxgui
.endif
