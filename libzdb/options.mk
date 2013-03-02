# $NetBSD: options.mk,v 1.3 2013/03/02 15:17:34 tnn2 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zdb
PKG_SUPPORTED_OPTIONS=		ssl sqliteunlock
PKG_SUGGESTED_OPTIONS=		ssl mysql
PKG_OPTIONS_NONEMPTY_SETS=	database
PKG_OPTIONS_SET.database=	mysql pgsql sqlite

.include "../../mk/bsd.options.mk"

###
### Support using a MySQL database server
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### Support using a PostgreSQL database server
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

###
### Support using a SQLite database
###
.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}
.  if !empty(PKG_OPTIONS:Msqliteunlock)
CONFIGURE_ARGS+=	--enable-sqliteunlock
.  endif
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

###
### Support OpenSSL cryptographic library
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-openssl
.  include "../../security/openssl/buildlink3.mk"
.endif
