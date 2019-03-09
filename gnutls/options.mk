# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	unbound
PLIST_VARS+=		unbound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Munbound)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST.unbound=		yes
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif
