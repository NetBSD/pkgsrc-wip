# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk14
PKG_SUPPORTED_OPTIONS=	opengl pango
PKG_SUGGESTED_OPTIONS=	opengl pango
PLIST_VARS+=		opengl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.     include "../../graphics/MesaLib/buildlink3.mk"
.     include "../../graphics/glu/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=		yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

.if !empty(PKG_OPTIONS:Mpango)
.  if ${OPSYS} != "Darwin"
#     Untested: Cocoa backend on macOS should use Core Text instead
.     include "../../devel/pango/buildlink3.mk"
.  endif
CONFIGURE_ARGS+=	--enable-pango
.else
CONFIGURE_ARGS+=	--disable-pango
.endif
