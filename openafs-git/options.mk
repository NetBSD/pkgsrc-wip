# $NetBSD: options.mk,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openafs
PKG_SUPPORTED_OPTIONS+=	server bitmap-later
PKG_SUPPORTED_OPTIONS+=	kernel-module supergroups namei
PKG_SUGGESTED_OPTIONS=	server -bitmap-later
PKG_SUGGESTED_OPTIONS+=	namei -kernel-module -supergroups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msupergroups)
CONFIGURE_ARGS+=	--enable-supergroups
.endif
.if !empty(PKG_OPTIONS:Mbitmap-later)
CONFIGURE_ARGS+=	--enable-bitmap-later
.endif
.if !empty(PKG_OPTIONS:Mkernel-module)
CONFIGURE_ARGS+=	--enable-kernel-module
.else
CONFIGURE_ARGS+=	--disable-kernel-module
.endif
.if !empty(PKG_OPTIONS:Mnamei)
CONFIGURE_ARGS+=	--enable-namei-fileserver
.endif
