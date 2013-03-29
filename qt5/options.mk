# $NetBSD: options.mk,v 1.1 2013/03/29 11:25:11 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5-libs
PKG_SUPPORTED_OPTIONS=	openssl
PKG_SUGGESTED_OPTIONS+=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif
