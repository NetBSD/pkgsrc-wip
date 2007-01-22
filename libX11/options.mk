# $NetBSD: options.mk,v 1.1 2007/01/22 09:40:09 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libX11
PKG_SUPPORTED_OPTIONS=	xcb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxcb)
. include "../../wip/libxcb/buildlink3.mk"
  CONFIGURE_ARGS+=	--with-xcb
.else
  CONFIGURE_ARGS+=	--without-xcb
.endif
