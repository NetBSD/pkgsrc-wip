# $NetBSD: options.mk,v 1.1 2012/08/07 19:41:18 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-carbon
PKG_SUPPORTED_OPTIONS=	amqp ldap memcached
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

###
### AMQP support
###
.if !empty(PKG_OPTIONS:Mamqp)
DEPENDS+=	${PYPKGPREFIX}-txamqp-[0-9]*:../../wip/py-txamqp
.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif

###
### Memcached support
###
.if !empty(PKG_OPTIONS:Mmemcached)
DEPENDS+=	${PYPKGPREFIX}-[0-9]*:../../wip/py-memcached
.endif
