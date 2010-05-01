# $NetBSD: options.mk,v 1.1 2010/05/01 22:14:05 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.meta-tracker
PKG_SUPPORTED_OPTIONS=	gnome
PKG_SUGGESTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.5
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.endif
