# $NetBSD: buildlink3.mk,v 1.1 2015/01/01 08:32:21 obache Exp $
#

BUILDLINK_TREE+=	mate-control-center

.if !defined(MATE_CONTROL_CENTER_BUILDLINK3_MK)
MATE_CONTROL_CENTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-control-center+=	mate-control-center>=1.8.3
BUILDLINK_PKGSRCDIR.mate-control-center?=	../../wip/mate-control-center

#.include "../../wip/libmatekbd/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-menus/buildlink3.mk"
#.include "../../wip/marco/buildlink3.mk"
#.include "../../wip/mate-settings-daemon/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../sysutils/dbus/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libunique/buildlink3.mk"
#.include "../../x11/libXi/buildlink3.mk"
#.include "../../x11/libXcursor/buildlink3.mk"
#.include "../../x11/libXft/buildlink3.mk"
.endif	# MATE_CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-control-center
