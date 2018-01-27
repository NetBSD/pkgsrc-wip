# $NetBSD: options.mk,v 1.3 2012/11/16 18:26:10 kristerw Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.semanticscuttle

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite oracle

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### MySQL >= 4.1 backend
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
.endif

###
### PostgreSQL backend
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
.endif

###
### SQLite backend
###
.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite/buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
.endif

###
### Oracle backend
###
.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	${PHP_PKG_PREFIX}-oci8-[0-9]*:../../databases/php-oci8
.endif
