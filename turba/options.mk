# $NetBSD: options.mk,v 1.1 2005/02/17 13:38:54 adrian_p Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.turba
PKG_SUPPORTED_OPTIONS=	ldap mysql

.if !defined(PKG_OPTIONS.turba)
PKG_DEFAULT_OPTIONS+=	ldap
.endif

.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for storing data
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	php-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use MySQL for storing data
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	php-mysql>=4.3.3:../../databases/php-mysql
.endif
