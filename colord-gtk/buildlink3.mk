# $NetBSD$

BUILDLINK_TREE+=	colord-gtk

.if !defined(COLORD_GTK_BUILDLINK3_MK)
COLORD_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord-gtk+=	colord-gtk>=0.1.26
BUILDLINK_PKGSRCDIR.colord-gtk?=	../../wip/colord-gtk

.include "../../x11/gtk3/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.endif	# COLORD_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord-gtk
