# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.pan2_git
PKG_OPTIONS_REQUIRED_GROUPS=	gtkversion
PKG_OPTIONS_GROUP.gtkversion=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--with-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.else
.include "../../x11/gtk2/buildlink3.mk"
.endif

# TODO: add options for:
#.include "../../security/libgnome-keyring/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../sysutils/libnotify07/buildlink3.mk"
#.include "../../www/webkit-gtk/buildlink3.mk"
# TODO: add debug option:
#CONFIGURE_ARGS=	--enable-debug
#CONFIGURE_ENV+=	CXXFLAGS=-ggdb
#CONFIGURE_ENV+=	CFLAGS=-ggdb
#CONFIGURE_ENV+=	LDFLAGS=-ggdb
