# $NetBSD: options.mk,v 1.1 2014/05/30 11:21:00 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.oce
PKG_SUPPORTED_OPTIONS=	draw x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	draw x11

.if !empty(PKG_OPTIONS:Mx11)
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.freetype2}/include
PLIST.x11=	yes
.  include "../../graphics/Mesa/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DOCE_DISABLE_X11=ON
.endif

.if !empty(PKG_OPTIONS:Mdraw)
.  if !empty(PKG_OPTIONS:Mx11)
CMAKE_ARGS+=	-DOCE_DRAW:BOOL=ON
PLIST.draw=	yes
.    include "../../lang/tcl/buildlink3.mk"
.    include "../../x11/tk/buildlink3.mk"
.  else
PKG_FAIL_REASON+=	"The 'draw' option requires the 'x11' option"
.  endif
.endif
