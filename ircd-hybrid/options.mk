# $NetBSD: options.mk,v 1.3 2006/01/03 13:09:25 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif
