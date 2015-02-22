# $NetBSD: options.mk,v 1.1 2015/02/22 15:50:27 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rng-tools
PKG_SUPPORTED_OPTIONS=	libgcrypt
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgcrypt
.else
CONFIGURE_ARGS+=	--without-libgcrypt
.endif
