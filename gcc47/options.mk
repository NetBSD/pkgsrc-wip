# $NetBSD: options.mk,v 1.2 2012/03/17 14:43:01 keckhardt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc47
PKG_SUPPORTED_OPTIONS=	nls noquadmath
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
.if !empty(PKG_OPTIONS:Mnoquadmath)
CONFIGURE_ARGS+=	--disable-libquadmath --disable-libquadmath-support
.endif

