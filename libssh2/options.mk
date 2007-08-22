# $NetBSD: options.mk,v 1.1 2007/08/22 06:43:13 bsadewitz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libssh2
PKG_OPTIONS_GROUP.crypto=	ssl libgcrypt
PKG_OPTIONS_OPTIONAL_GROUPS=	crypto
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-libgcrypt
.	include "../../security/openssl/buildlink3.mk"

.elif !empty(PKG_OPTIONS:Mlibgcrypt)
CONFIGURE_ARGS+=	--with-libgcrypt
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt:Q}
CONFIGURE_ARGS+=	--without-openssl
.	include	"../../security/libgcrypt/buildlink3.mk"
.endif
