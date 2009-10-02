# $NetBSD: options.mk,v 1.2 2009/10/02 16:43:34 fhajny Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sphinx-search
PKG_OPTIONS_NONEMPTY_SETS=	db
PKG_OPTIONS_SET.db=		mysql pgsql
PKG_SUPPORTED_OPTIONS=		iconv
PKG_SUGGESTED_OPTIONS=		mysql iconv

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Miconv)
CONFIGURE_ARGS+=	--with-iconv
LDFLAGS+=		-liconv
.  include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-iconv
.endif
