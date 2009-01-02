# $NetBSD: options.mk,v 1.14 2009/01/02 23:31:56 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm-nightly
PKG_SUPPORTED_OPTIONS=	scummvm-nightly-cruise
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-igor
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-m4
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-made
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-saga2
PKG_SUPPORTED_OPTIONS+=	scummvm-nightly-tinsel
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
.if !empty(PKG_OPTIONS:Mscummvm-nightly-saga2)
CONFIGURE_ARGS+=--enable-saga2
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-tinsel)
CONFIGURE_ARGS+=--enable-tinsel
.endif
