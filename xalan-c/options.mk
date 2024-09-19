# $NetBSD: options.mk,v 1.1 2013/01/22 13:25:15 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xalan-c
PKG_SUPPORTED_OPTIONS=	icu
PKG_SUGGESTED_OPTIONS=	icu

.include "../../mk/bsd.options.mk"

###
### Whether to build with ICU.
###
.if !empty(PKG_OPTIONS:Micu)
CONFIGURE_ARGS+=	-t icu
XALAN_ENV+=	ICUROOT="${PREFIX}"
PLIST_SRC+=	PLIST.icu
.include "../../textproc/icu/buildlink3.mk"
.else
.endif

