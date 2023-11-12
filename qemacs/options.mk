### Set options
PKG_OPTIONS_VAR=			PKG_OPTIONS.qemacs
PKG_SUPPORTED_OPTIONS=			x11 tiny ffmpeg xrender html png xshm plugins xv
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtiny)
CONFIGURE_ARGS+=	--enable-tiny
.else
CONFIGURE_ARGS+=	--disable-tiny
.endif

### plugins are enabled by default
.if empty(PKG_OPTIONS:Mplugins)
CONFIGURE_ARGS+=	--disable-plugins
.endif


.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
.endif

.if !empty(PKG_OPTIONS:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xrender
.endif

.if !empty(PKG_OPTIONS:Mhtml)
CONFIGURE_ARGS+=	--enable-html
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-png
.endif

.if !empty(PKG_OPTIONS:Mxshm)
.include "../../x11/libxshmfence/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xshm
.endif

.if !empty(PKG_OPTIONS:Mxv)
.include "../../x11/libXv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-xv
.endif
