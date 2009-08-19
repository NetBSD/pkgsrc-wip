# $NetBSD: options.mk,v 1.1.1.1 2009/08/19 18:09:29 udontknow Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.zdb
PKG_SUPPORTED_OPTIONS=	ssl sqliteunlock
PKG_SUGGESTED_OPTIONS=	ssl
PKG_OPTIONS_NONEMPTY_SETS= database
PKG_OPTIONS_SET.database=  mysql pgsql sqlite

.include "../../mk/bsd.options.mk"

###
### Support using a MySQL database server
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
.endif

###
### Support using a PostgreSQL database server
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
.endif

###
### Support using a SQLite database
###
.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Msqliteunlock)
CONFIGURE_ARGS+=--enable-sqliteunlock
.  endif
.endif

###
### Support OpenSSL cryptographic library
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=        --enable-openssl
.  include "../../security/openssl/buildlink3.mk"
.endif
