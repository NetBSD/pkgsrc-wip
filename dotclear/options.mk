# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.dotclear

PKG_OPTIONS_REQUIRED_GROUPS=	db webserver
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite
PKG_OPTIONS_GROUP.webserver=	apache nginx

PKG_SUGGESTED_OPTIONS=		apache mysql

.include "../../mk/bsd.options.mk"

###
### Use apache web server
###
.if !empty(PKG_OPTIONS:Mapache)
WWW_USER?=              ${APACHE_USER}
WWW_GROUP?=             ${APACHE_GROUP}
BUILD_DEFS+=		APACHE_USER APACHE_GROUP
.include "../../mk/apache.mk"
DEPENDS+=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=5.5:../../www/ap-php
WWW_CONF_FILE=		apache24.conf
WWW_SYSCONFDIR=		${PREFIX}/etc/httpd
.endif

###
### Use nginx web server
###
.if !empty(PKG_OPTIONS:Mnginx)
DEPENDS+=		nginx-[0-9]*:../../www/nginx
DEPENDS+=		${PHP_PKG_PREFIX}-fpm>=5.5:../../www/php-fpm
WWW_USER?=		nginx
WWW_GROUP?=		nginx
WWW_CONF_FILE=		nginx.conf
WWW_SYSCONFDIR=		${PREFIX}/etc/nginx
.endif
###
### Use mysql backend.
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
.endif

###
### Use pgsql backend.
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
.endif

###
### Use sqlite backend.
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite
OWN_DIRS_PERMS+=	${VARBASE}/db/dotclear \
			${WWW_USER} ${WWW_GROUP} 750
.endif
