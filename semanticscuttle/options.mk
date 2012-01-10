# $NetBSD: options.mk,v 1.1.1.1 2012/01/10 10:09:14 triaxx Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.semanticscuttle

PKG_OPTIONS_REQUIRED_GROUPS= db
PKG_OPTIONS_GROUP.db= mysql

PKG_SUGGESTED_OPTIONS= mysql

.include "../../mk/bsd.options.mk"

###
### MySQL >= 4.1 backend
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-mysqli:../../databases/php-mysqli
.endif
