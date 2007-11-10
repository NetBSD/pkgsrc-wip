# $NetBSD: options.mk,v 1.1 2007/11/10 22:33:21 zul_ Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mcabber
PKG_SUPPORTED_OPTIONS=	ssl gpgme otr aspell
PKG_SUGGESTED_OPTIONS=  gpgme ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgpgme)
.include "../../security/gpgme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif

.if !empty(PKG_OPTIONS:Motr)
.include "../../chat/libotr/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-otr
.endif

.if !empty(PKG_OPTIONS:Maspell)
.include "../../textproc/aspell/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-aspell
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-ssl
.endif
