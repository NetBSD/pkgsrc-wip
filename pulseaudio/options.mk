# $NetBSD: options.mk,v 1.6 2015/03/22 14:16:50 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pulseaudio
PKG_SUPPORTED_OPTIONS=	avahi x11 fftw gconf jack
PKG_SUGGESTED_OPTIONS=	avahi x11 fftw gconf jack
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}
.include "../../mk/bsd.options.mk"

PLIST_SRC+=	${PKGDIR}/PLIST
###
### avahi
###
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=		yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

###
### fftw ( buildlink to fftwf )
###
.if !empty(PKG_OPTIONS:Mfftw)
.include "../../math/fftwf/buildlink3.mk"
PLIST_SRC+=	${PKGDIR}/PLIST.fftwf
.else
CONFIGURE_ARGS+=	--disable-fftw
.endif

###
### gconf
###
.if !empty(PKG_OPTIONS:Mgconf)
.include "../../devel/GConf/buildlink3.mk"
PLIST_SRC+=	${PKGDIR}/PLIST.gconf
.else
CONFIGURE_ARGS+=	--disable-gconf
.endif

###
### jack
###
.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
PLIST_SRC+=	${PKGDIR}/PLIST.jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

###
### X11
###
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--disable-x11
.endif
