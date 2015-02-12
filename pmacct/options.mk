# $NetBSD: options.mk,v 1.2 2015/02/12 19:06:40 mbowie Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pmacct
PKG_SUPPORTED_OPTIONS=	geoip inet6 json pgsql
PKG_SUGGESTED_OPTIONS=	inet6 json

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
.  include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mjson)
.  include "../../textproc/jansson/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-jansson
.else
CONFIGURE_ARGS+=	--disable-jansson
.endif

PLIST_VARS+=		pgsql
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pgsql
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif
