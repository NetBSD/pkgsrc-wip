# $NetBSD: options.mk,v 1.1 2012/03/19 00:28:17 bubuchka Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.leveldb
PKG_SUPPORTED_OPTIONS=	snappy
PKG_SUGGESTED_OPTIONS=	snappy

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		snappy

.if !empty(PKG_OPTIONS:Msnappy)
.include "../../devel/snappy/buildlink3.mk"
.endif
