# $NetBSD: options.mk,v 1.1.1.1 2011/08/05 10:20:22 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aravis
PKG_SUPPORTED_OPTIONS=	cairo gstreamer 
PKG_SUGGESTED_OPTIONS=	cairo gstreamer

.include "../../mk/bsd.options.mk"

###
### cairo support
###
.if !empty(PKG_OPTIONS:Mcairo)
CONFIGURE_ARGS+=	--enable-cairo
.  include "../../graphics/cairo/buildlink3.mk"
.endif

###
### gstreamer support
###
.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-gstreamer
.  include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif
