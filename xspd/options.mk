# $NetBSD: options.mk,v 1.3 2006/12/23 00:00:41 kcf Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.xspd
PKG_SUPPORTED_OPTIONS=	netbsd semctlunion bitmode64
PKG_SUGGESTED_OPTIONS=	netbsd semctlunion

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
BITMODE=	64
.else
BITMODE=	32
.endif
