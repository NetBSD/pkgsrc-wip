# $NetBSD: options.mk,v 1.2 2007/01/23 15:52:54 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libXfont
PKG_SUPPORTED_OPTIONS=	inet6 libxfont-unix-transport libxfont-tcp-transport
PKG_SUGGESTED_OPTIONS=	libxfont-unix-transport libxfont-tcp-transport

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mipv6)
  CONFIGURE_ARGS+=	--enable-ipv6
.endif


.if !empty(PKG_OPTIONS:Mlibxfont-unix-transport)
  CONFIGURE_ARGS+=	--enable-unix-domain-transport
.endif


.if !empty(PKG_OPTIONS:Mlibxfont-tcp-transport)
  CONFIGURE_ARGS+=	--enable-tcp-transport
.endif
