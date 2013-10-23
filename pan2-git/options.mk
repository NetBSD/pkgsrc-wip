# $NetBSD: options.mk,v 1.1 2013/10/23 21:32:28 rhialto Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pan2_git
PKG_OPTIONS_REQUIRED_GROUPS=	gtkversion
PKG_OPTIONS_GROUP.gtkversion=   gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.else
.include "../../x11/gtk2/buildlink3.mk"
.endif
