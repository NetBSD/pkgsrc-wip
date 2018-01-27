# $NetBSD: options.mk,v 1.1.1.1 2008/08/22 05:10:37 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hengband

PKG_SUPPORTED_OPTIONS= \
	japanese \
	ncurses \
	x11

PKG_SUGGESTED_OPTIONS= \
	ncurses \
	x11

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mjapanese)
CONFIGURE_ARGS+=	--disable-japanese
.endif

.if !empty(PKG_OPTIONS:Mncurses)
.include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif
