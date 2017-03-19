# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.rspamd15

PKG_SUPPORTED_OPTIONS=	gd

.include "../../mk/bsd.options.mk"

###
### Enable fuzzy matching for images
###
.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GD=ON
.else
CMAKE_ARGS+=	-DENABLE_GD=OFF
.endif

