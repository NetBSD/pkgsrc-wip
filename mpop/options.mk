# $NetBSD: options.mk,v 1.1.1.1 2005/11/12 16:52:05 leonardschmidt Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpop
PKG_SUPPORTED_OPTIONS=		gsasl nls
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		nls ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mgsasl)
CONFIGURE_ARGS+=	--enable-gsasl
.  include "../../security/gsasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST_SUBST+=		NLS=""
.else
PLIST_SUBST+=		NLS="@comment "
.endif
