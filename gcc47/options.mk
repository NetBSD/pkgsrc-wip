# $NetBSD: options.mk,v 1.3 2012/03/17 15:38:29 keckhardt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc47
PKG_SUPPORTED_OPTIONS=	nls gcc-quadmath
PKG_SUGGESTED_OPTIONS=  
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.endif

.include "../../mk/bsd.options.mk"

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### quadmath 
###
.if empty(PKG_OPTIONS:Mgcc-quadmath)
CONFIGURE_ARGS+=	--disable-libquadmath --disable-libquadmath-support
.endif

