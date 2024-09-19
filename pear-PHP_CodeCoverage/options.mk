# $NetBSD: options.mk,v 1.1 2013/07/14 12:30:42 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pear-PHP_CodeCoverage
PKG_SUPPORTED_OPTIONS=	dom xdebug
PKG_SUGGESTED_OPTIONS=	dom xdebug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdom)
DEPENDS+=		${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
.endif

.if !empty(PKG_OPTIONS:Mxdebug)
DEPENDS+=		xdebug>=2.0.5:../../wip/xdebug
.endif
