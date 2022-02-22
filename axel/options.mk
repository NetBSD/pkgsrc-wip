# $NetBSD$
PKG_OPTIONS_VAR=		PKG_OPTIONS.axel
PKG_SUPPORTED_OPTIONS=		nls ssl
PKG_SUGGESTED_OPTIONS=		nls ssl
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		openssl libressl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_SRC=		PLIST
.if !empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-lib/buildlink3.mk"
PLIST_SRC+=		PLIST.nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

PKG_SUGGESTED_OPTIONS+=	${PKG_OPTIONS_GROUP.ssl:[1]}
.if empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-ssl
PKG_OPTIONS:=		${PKG_OPTIONS:N*ssl}
.else
.  if empty(PKG_OPTIONS:M*?ssl)
PKG_OPTIONS+=		${PKG_OPTIONS_GROUP.ssl:[1]}
.  endif
LIBSSL:=		${PKG_OPTIONS:M*?ssl}
.  include "../../security/${LIBSSL}/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.${LIBSSL}}
USE_TOOLS+=		pkg-config
.endif
