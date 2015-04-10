# $NetBSD: buildlink3.mk,v 1.4 2015/04/10 12:42:12 krytarowski Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk3

.if !defined(LIBDBUSMENU_GTK3_BUILDLINK3_MK)
LIBDBUSMENU_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk3+=	libdbusmenu-gtk3>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk3?=	../../wip/libdbusmenu-gtk3

.include "../../wip/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk3
