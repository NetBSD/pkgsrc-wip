# $NetBSD: options.mk,v 1.1 2015/08/19 19:36:55 yhardy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opentyrian
PKG_SUPPORTED_OPTIONS=		opl3 tyrian2000
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopl3)
CFLAGS+=	-DOPLTYPE_IS_OPL3
.endif

.if !empty(PKG_OPTIONS:Mtyrian2000)
CFLAGS+=	-DTYRIAN2000
.endif
