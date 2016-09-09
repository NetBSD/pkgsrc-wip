# $NetBSD: options.mk,v 1.2 2015/01/25 20:05:54 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sync-server-dependencies
PKG_SUPPORTED_OPTIONS=	apache
PKG_SUGGESTED_OPTIONS=	apache

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapache)
DEPENDS+=	${PYPKGPREFIX}-${APACHE_PKG_PREFIX}-mod_wsgi-[0-9]*:../../www/py-mod_wsgi
.include "../../mk/apache.mk"
.endif
