# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-basercms

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql, pgsql, or sqlite backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=8.1.0:../../databases/php-pdo_mysql
.elif !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=8.1.0:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite3>=8.1.0:../../databases/php-sqlite3
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=8.1.0:../../databases/php-pdo_pgsql
.endif
