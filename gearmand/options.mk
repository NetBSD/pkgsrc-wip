# $NetBSD: options.mk,v 1.1.1.1 2012/02/14 10:15:13 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gearmand
PKG_SUPPORTED_OPTIONS+=	dtrace memcached pgsql sqlite tokyocabinet

.include "../../mk/bsd.options.mk"

###
### DTrace support
###
.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace
.else
CONFIGURE_ARGS+=	--disable-dtrace
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-libpq
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}/bin/pg_config
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libpq
.endif

###
### SQLite3 support
###
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sqlite3=no
.endif

###
### memcached support
###
.if !empty(PKG_OPTIONS:Mmemcached)
CONFIGURE_ARGS+=	--enable-libmemcached
CONFIGURE_ARGS+=	--with-memcached=${BUILDLINK_PREFIX.memcached}/bin/memcached
.include "../../devel/libmemcached/buildlink3.mk"
BUILD_DEPENDS+=		memcached-[0-9]*:../../devel/memcached
.else
CONFIGURE_ARGS+=	--disable-libmemcached
.endif

### Tokyo Cabinet support
.if !empty(PKG_OPTIONS:Mtokyocabinet)
CONFIGURE_ARGS+=	--enable-libtokyocabinet
.include "../../databases/tokyocabinet/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libtokyocabinet
.endif
