# $NetBSD: buildlink3.mk,v 1.3 2015/04/09 02:40:34 krytarowski Exp $
#

BUILDLINK_TREE+=	mate-panel

.if !defined(MATE_PANEL_BUILDLINK3_MK)
MATE_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-panel+=	mate-panel>=1.8.1
BUILDLINK_PKGSRCDIR.mate-panel?=	../../wip/mate-panel

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif	# MATE_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-panel
