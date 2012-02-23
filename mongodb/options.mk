# $NetBSD: options.mk,v 1.1 2012/02/23 19:11:40 bartoszkuzma Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_ARGS+=		--ssl
.endif
