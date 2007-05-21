# $NetBSD: options.mk,v 1.2 2007/05/21 10:08:11 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm-nightly
PKG_SUPPORTED_OPTIONS=	scummvm-nightly-cruise scummvm-nightly-lure
PKG_SUGGESTED_OPTIONS=	scummvm-nightly-cruise scummvm-nightly-lure

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mscummvm-nightly-cruise)
CONFIGURE_ARGS+=--enable-cruise
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-lure)
CONFIGURE_ARGS+=--enable-lure
.endif
