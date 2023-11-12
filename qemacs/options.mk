# $NetBSD$
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.qemacs
PKG_SUPPORTED_OPTIONS=	x11 tiny xrender html png xshm plugins xv
PKG_SUGGESTED_OPTIONS=	x11

PLIST_VARS+=	html

.include "../../mk/bsd.options.mk"

###
### Produce a tiny build (disables all other options)
###
.if !empty(PKG_OPTIONS:Mtiny)
CONFIGURE_ARGS+=	--enable-tiny
.else
CONFIGURE_ARGS+=	--disable-tiny
.endif

###
### Support Qemacs plugins
###
.if empty(PKG_OPTIONS:Mplugins)
CONFIGURE_ARGS+=	--disable-plugins
.endif

###
### Support x11
###
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
.endif

###
### Support xrender
###
.if !empty(PKG_OPTIONS:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xrender
.endif

###
### Support rendering HTML in Qemacs
###
.if !empty(PKG_OPTIONS:Mhtml)
CONFIGURE_ARGS+=	--enable-html
PLIST.html=		yes
.endif

###
### Support viewing PNG images in Qemacs
###
.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-png
.endif

###
### Support xshm
###
.if !empty(PKG_OPTIONS:Mxshm)
.include "../../x11/libxshmfence/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xshm
.endif

###
### Support Xvideo
###
.if !empty(PKG_OPTIONS:Mxv)
.include "../../x11/libXv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xv
.endif
