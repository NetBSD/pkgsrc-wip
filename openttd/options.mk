# $NetBSD: options.mk,v 1.3 2010/08/29 10:27:07 ggergely Exp $
.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openttd
PKG_SUPPORTED_OPTIONS=	openttd-data
PKG_SUGGESTED_OPTIONS=	openttd-data

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenttd-data)
DEPENDS+=	openttd-opengfx:../../wip/openttd-opengfx
DEPENDS+=	openttd-opensfx:../../wip/openttd-opensfx
DEPENDS+=	openttd-openmsx:../../wip/openttd-openmsx
.endif
