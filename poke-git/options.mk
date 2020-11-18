# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.poke-git
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_FLAGS+=	--enable-gui
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif
