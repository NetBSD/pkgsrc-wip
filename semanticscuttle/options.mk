# $NetBSD: options.mk,v 1.2 2012/01/11 07:19:01 triaxx Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.semanticscuttle

PKG_OPTIONS_REQUIRED_GROUPS= db
PKG_OPTIONS_GROUP.db= mysql pgsql sqlite oracle

PKG_SUGGESTED_OPTIONS= mysql

.include "../../mk/bsd.options.mk"

###
### MySQL >= 4.1 backend
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-mysqli:../../databases/php-mysqli
.endif

###
### PostgreSQL backend
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-pgsql:../../databases/php-pgsql
.endif

###
### SQLite backend
###
.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite/buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite:../../databases/php-sqlite
.endif

###
### Oracle backend
###
.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	${PHP_PKG_PREFIX}-oci8:../../databases/php-oci8
.endif
