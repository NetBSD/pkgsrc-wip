# $NetBSD: options.mk,v 1.1.1.1 2009/08/03 19:38:44 athaba Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.syx
PKG_SUPPORTED_OPTIONS=	gmp gtk readline x11
PKG_SUGGESTED_OPTIONS=	gmp gtk readline x11

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-readline
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-x11
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk/buildlink3.mk"
CONFIGURE_ARGS+=        --enable-gtk
.endif

.if !empty(PKG_OPTIONS:Mgmp)
.include "../../devel/gmp/buildlink3.mk"
CONFIGURE_ARGS+=        --with-gmp
.endif
