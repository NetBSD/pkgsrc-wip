# $NetBSD$
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.qemacs
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

PLIST_VARS+=	html

.include "../../mk/bsd.options.mk"

# maybe consider ffmpeg, xv and xshm support later

###
### Support x11
###
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-html
CONFIGURE_ARGS+=	--enable-png
PLIST.html=            yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
CONFIGURE_ARGS+=	--disable-html
CONFIGURE_ARGS+=	--disable-png
.endif
