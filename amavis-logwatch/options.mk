# $NetBSD: options.mk,v 1.1 2013/07/01 11:44:42 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amavis-logwatch
PKG_SUPPORTED_OPTIONS+=	logwatch

PKG_SUGGESTED_OPTIONS+=	logwatch

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlogwatch)
.include "../../wip/postfix-logwatch/Makefile.logwatch"
.else
.include "../../wip/postfix-logwatch/Makefile.standalone"
.endif
