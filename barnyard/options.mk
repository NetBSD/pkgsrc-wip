# $NetBSD: options.mk,v 1.1 2005/05/02 17:42:56 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.barnyard
PKG_SUPPORTED_OPTIONS=	mysql pgsql

.if !defined(PKG_OPTIONS.barnyard)
PKG_DEFAULT_OPTIONS+=	mysql
.endif

.include "../../mk/bsd.options.mk"

###
### Use PostgreSQL for storing user details
###
.if !empty(PKG_OPTIONS:Mpostgresql)
.	include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-postgres
CONFIGURE_ARGS+=	--with-postgres-includes=${PREFIX}/include/postgresql
CONFIGURE_ARGS+=	--with-postgres-libraries=${PREFIX}/lib/postgresql
LIBS+=			${COMPILER_RPATH_FLAG}${PREFIX}/lib/postgresql
.endif

###
### Use MySQL for storing user details
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${PREFIX}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libraries=${PREFIX}/lib/mysql
LIBS+=   		${COMPILER_RPATH_FLAG}${PREFIX}/lib/mysql
.endif
