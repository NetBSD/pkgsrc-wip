# $NetBSD: options.mk,v 1.1 2012/09/19 14:22:17 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ap22-authz-ldap
PKG_SUPPORTED_OPTIONS=	openssl
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl-path=${BUILDLINK_PREFIX.openssl}
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
