# $NetBSD: options.mk,v 1.1 2012/11/03 16:47:20 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wput
PKG_SUPPORTED_OPTIONS=	gnutls nls
PKG_SUGGESTED_OPTIONS+=	gnutls nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+=	--with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nls
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
