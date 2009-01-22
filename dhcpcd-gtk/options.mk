# $NetBSD: options.mk,v 1.1.1.1 2009/01/22 16:09:05 rsmarples Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dhcpcd-gtk

PKG_SUPPORTED_OPTIONS=	gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnomeui/buildlink3.mk"
MAKE_ENV+=		DE=GNOME
.endif
