# $NetBSD: options.mk,v 1.1.1.1 2008/01/07 10:36:40 hoka_adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets
PKG_SUGGESTED_OPTIONS=		wxwidgets

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST_SUBST+=		COND_SKINS=
.else
CONFIGURE_ARGS+=	--disable-skins2
PLIST_SUBST+=		COND_SKINS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mwxwidgets)
.include "../../x11/wxGTK/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wxwidgets
PLIST_SUBST+=		COND_WXWIDGETS=
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
PLIST_SUBST+=		COND_WXWIDGETS="@comment "
.endif
