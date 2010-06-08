# $NetBSD: options.mk,v 1.1.1.1 2010/06/08 08:48:25 tonnerre Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.serendipity

PKG_OPTIONS_REQUIRED_GROUPS=	serendipity
PKG_OPTIONS_GROUP.serendipity=	php-cgi ap-php pgsql mysql

PKG_SUGGESTED_OPTIONS=		ap-php pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
.  if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php>=4.4.7:../../www/php4
.  endif
.  if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.4:../../lang/php5
.  endif
.endif

.if !empty(PKG_OPTIONS:Map-php)
.  include "../../mk/apachever.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.0:../../www/ap-php
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.0:../../databases/php-pgsql
.endif

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.0:../../databases/php-mysql
.endif
