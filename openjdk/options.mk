# $NetBSD: options.mk,v 1.1 2009/10/06 18:33:17 tnn2 Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openjdk7
PKG_SUPPORTED_OPTIONS=	openjdk7-icedtea-plugin
PKG_SUGGESTED_OPTIONS=	# openjdk7-icedtea-plugin

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	plugin

.if !empty(PKG_OPTIONS:Mopenjdk7-icedtea-plugin)
PLIST.plugin=	yes
.  include "icedtea-extras.mk"
.endif
