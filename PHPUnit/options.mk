# $NetBSD: options.mk,v 1.1 2013/07/14 12:59:00 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pear-PHPUnit
PKG_SUPPORTED_OPTIONS=	invoker
PKG_SUGGESTED_OPTIONS=	invoker

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdom)
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Invoker>=1.1.2:../../wip/pear-PHP_Invoker
.endif
