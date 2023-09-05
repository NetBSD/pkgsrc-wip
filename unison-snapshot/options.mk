# $NetBSD: options.mk,v 1.6 2022/03/13 15:07:13 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk
PKG_SUGGESTED_OPTIONS=	lablgtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk3

.if !empty(PKG_OPTIONS:Mlablgtk)
PLIST.gtk3=	yes
DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc

.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.endif
