# $NetBSD: options.mk,v 1.1 2015/01/03 07:10:32 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboobs
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif
