# $NetBSD: options.mk,v 1.2 2013/10/24 16:28:55 rhialto Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pan2_git
PKG_OPTIONS_REQUIRED_GROUPS=	gtkversion
PKG_OPTIONS_GROUP.gtkversion=   gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--with-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.else
.include "../../x11/gtk2/buildlink3.mk"
.endif
