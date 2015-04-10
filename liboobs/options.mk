# $NetBSD: options.mk,v 1.3 2015/04/10 12:24:57 krytarowski Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboobs
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif
