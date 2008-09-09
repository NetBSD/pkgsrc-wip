# $NetBSD: options.mk,v 1.1.1.1 2008/09/09 20:04:03 shindenmorr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wordpress
PKG_OPTIONS_REQUIRED_GROUPS=	wordpress
PKG_OPTIONS_GROUP.wordpress=	php-cgi ap-php

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mphp-cgi)
.include "../../lang/php/phpversion.mk"
.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php>=4.4.7:../../www/php4
.endif
.if ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php>=5.2.4:../../lang/php5
.endif
.endif

.if !empty(PKG_OPTIONS:Map-php)
.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.0:../../www/ap-php
.endif
