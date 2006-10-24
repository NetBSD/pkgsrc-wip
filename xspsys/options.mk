PKG_OPTIONS_VAR=	PKG_OPTIONS.xspsys
PKG_SUPPORTED_OPTIONS=	netbsd semctl_union bitmode64
PKG_SUGGESTED_OPTIONS=	netbsd semctl_union

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnetbsd)
MAKE_ENV+=	UNAME="NetBSD"
.endif

#Select if semctl() requires a union.
.if !empty(PKG_OPTIONS:Msemctl_union)
MAKE_ENV+=	SEMUN="1"
.else
MAKE_ENV+=	SEMUN="0"
.endif

.if !empty(PKG_OPTIONS:Mbitmode64)
MAKE_ENV+=	BITMODE="64"
.else
MAKE_ENV+=	BITMODE="32"
.endif
