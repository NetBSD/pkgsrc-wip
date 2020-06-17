# $NetBSD$

BUILDLINK_TREE+=	gnome-autoar

.if !defined(GNOME_AUTOAR_BUILDLINK3_MK)
GNOME_AUTOAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-autoar+=	gnome-autoar>=0.2.4
BUILDLINK_PKGSRCDIR.gnome-autoar?=	../../wip/gnome-autoar

#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../lang/vala/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
#.include "../../x11/gtk3/buildlink3.mk"
.endif	# GNOME_AUTOAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-autoar
