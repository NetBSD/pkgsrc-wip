# $NetBSD: options.mk,v 1.1.1.1 2006/03/19 18:46:27 airhead Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.siege
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
. include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
