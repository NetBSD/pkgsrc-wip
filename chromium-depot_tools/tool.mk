# $NetBSD: tool.mk,v 1.1 2014/08/31 17:10:48 heidnes Exp $

.if !defined(CHROMIUM_DEPOT_TOOLS_MK)
CHROMIUM_DEPOT_TOOLS_MK= defined

PREPEND_PATH+=  ${PREFIX}/share/chromium-depot_tools
MAKE_ENV+=	DEPOT_TOOLS_UPDATE=0

.endif #CHROMIUM_DEPOT_TOOLS_MK
