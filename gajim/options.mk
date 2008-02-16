# $NetBSD: options.mk,v 1.1 2008/02/16 23:03:05 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gajim
PKG_SUPPORTED_OPTIONS=	gtkspell dbus trayicon
PKG_SUGGESTED_OPTIONS=	gtkspell dbus trayicon

.include "../../mk/bsd.options.mk"

# gtkspell
.if !empty(PKG_OPTIONS:Mgtkspell)
.include "../../textproc/gtkspell/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtkspell
PLIST_SUBST+=	GTKSPELL=""
.else
CONFIGURE_ARGS+=	--disable-gtkspell
PLIST_SUBST+=	GTKSPELL="@comment "
.endif

# dbus
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/py-dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-remote
PLIST_SUBST+=	REMOTE=""
.else
CONFIGURE_ARGS+=	--disable-remote
PLIST_SUBST+=	REMOTE="@comment "
.endif

# trayicon
.if !empty(PKG_OPTIONS:Mtrayicon)
CONFIGURE_ARGS+=	--enable-trayicon
PLIST_SUBST+=	TRAYICON=""
.else
CONFIGURE_ARGS+=	--disable-trayicon
PLIST_SUBST+=	TRAYICON="@comment "
.endif
