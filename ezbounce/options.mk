# $NetBSD: options.mk,v 1.1 2013/01/20 22:12:46 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezbounce
PKG_SUPPORTED_OPTIONS=	debug openssl
PKG_SUGGESTED_OPTIONS+=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl
.endif
