# $NetBSD: options.mk,v 1.1 2007/05/13 07:30:55 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm-nightly
PKG_SUPPORTED_OPTIONS=	scummvm-nightly-cruise scummvm-nightly-lure scummvm-nightly-parallaction
PKG_SUGGESTED_OPTIONS=	scummvm-nightly-cruise scummvm-nightly-lure scummvm-nightly-parallaction

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mscummvm-nightly-cruise)
CONFIGURE_ARGS+=--enable-cruise
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-lure)
CONFIGURE_ARGS+=--enable-lure
.endif
.if !empty(PKG_OPTIONS:Mscummvm-nightly-parallaction)
CONFIGURE_ARGS+=--enable-parallaction
.endif
