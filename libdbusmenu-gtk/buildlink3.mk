# $NetBSD: buildlink3.mk,v 1.1 2015/01/12 11:32:43 obache Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk

.if !defined(LIBDBUSMENU_GTK_BUILDLINK3_MK)
LIBDBUSMENU_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk+=	libdbusmenu-gtk>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk?=	../../wip/libdbusmenu-gtk

.include "../../wip/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk
