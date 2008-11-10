# $NetBSD: options.mk,v 1.9 2008/11/10 20:48:57 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm-nightly
PKG_SUPPORTED_OPTIONS=	scummvm-nightly-cruise
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-igor
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-m4
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-made
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-tinsel
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-tucker
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mscummvm-nightly-cruise)
CONFIGURE_ARGS+=--enable-cruise
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-igor)
CONFIGURE_ARGS+=--enable-igor
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-m4)
CONFIGURE_ARGS+=--enable-m4
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-made)
CONFIGURE_ARGS+=--enable-made
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-tinsel)
CONFIGURE_ARGS+=--enable-tucker
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-tucker)
CONFIGURE_ARGS+=--enable-tinsel
.endif
