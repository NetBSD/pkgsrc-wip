# $NetBSD: options.mk,v 1.1 2008/12/08 07:58:15 tonnerre Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo2
PKG_SUPPORTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl

SUBST_CLASSES+=		ssl
SUBST_STAGE.ssl=	post-patch
SUBST_FILES.ssl=	dpi/https.c
SUBST_SED.ssl=		-e 72d

.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
