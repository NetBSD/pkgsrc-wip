# $NetBSD: buildlink3.mk,v 1.21 2012/09/15 10:06:24 obache Exp $

BUILDLINK_TREE+=	gnome-menus

.if !defined(GNOME_MENUS_BUILDLINK3_MK)
GNOME_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-menus+=		gnome-menus>=2.13.5
BUILDLINK_ABI_DEPENDS.gnome-menus+=	gnome-menus>=3.10.1nb1
BUILDLINK_PKGSRCDIR.gnome-menus?=	../../wip/gnome-menus

.include "../../devel/glib2/buildlink3.mk"
.endif # GNOME_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-menus
