# $NetBSD: buildlink3.mk,v 1.48 2015/04/25 14:25:04 tnn Exp $

BUILDLINK_TREE+=	gnome-control-center

.if !defined(GNOME_CONTROL_CENTER_BUILDLINK3_MK)
GNOME_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-control-center+=	gnome-control-center>=3.16.3
BUILDLINK_PKGSRCDIR.gnome-control-center?=	../../wip/gnome-control-center

.include "../../wip/gnome-menus/buildlink3.mk"
#.include "../../sysutils/gnome-vfs/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../wm/metacity/buildlink3.mk"
#.include "../../x11/gnome-desktop3/buildlink3.mk"
#.include "../../wip/gnome-panel/buildlink3.mk"
.endif # GNOME_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-control-center
