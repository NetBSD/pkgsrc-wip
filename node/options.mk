# $NetBSD: options.mk,v 1.3 2012/06/15 11:33:28 fhajny Exp $

PKG_OPTIONS_VAR=       PKG_OPTIONS.node
PKG_SUPPORTED_OPTIONS= openssl dtrace
PKG_SUGGESTED_OPTIONS= openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=       --with-dtrace
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --without-openssl
.endif

.if empty(PKG_OPTIONS:Msnapshot)
CONFIGURE_ARGS+=	--without-snapshot
.endif
