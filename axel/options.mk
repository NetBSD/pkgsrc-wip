# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.axel

PKG_SUPPORTED_OPTIONS=		nls
PKG_SUGGESTED_OPTIONS=		nls openssl

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		openssl libressl wolfssl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_SRC=		PLIST
.if !empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST_SRC+=		PLIST.nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
.elif !empty(PKG_OPTIONS:Mlibressl)
.  include "../../security/libressl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
.elif !empty(PKG_OPTIONS:Mwolfssl)
.  include "../../security/wolfssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=wolfssl
.else
CONFIGURE_ARGS+=       --without-ssl
.endif
