# $NetBSD: options.mk,v 1.2 2006/11/28 06:07:03 kcf Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.xspd
PKG_SUPPORTED_OPTIONS=	netbsd semctlunion bitmode64
PKG_SUGGESTED_OPTIONS=	netbsd semctlunion

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnetbsd)
MAKE_ENV+=	UNAME="NetBSD"
.endif

#Select if semctl() requires a union.
.if !empty(PKG_OPTIONS:Msemctlunion)
MAKE_ENV+=	SEMUN="1"
.else
MAKE_ENV+=	SEMUN="0"
.endif

.if !empty(PKG_OPTIONS:Mbitmode64)
MAKE_ENV+=	BITMODE="64"
.else
MAKE_ENV+=	BITMODE="32"
.endif
