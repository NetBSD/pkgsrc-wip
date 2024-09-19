# $NetBSD: buildlink3.mk,v 1.1 2013/07/15 20:14:21 thomasklausner Exp $

BUILDLINK_TREE+=	cairo-dock

.if !defined(CAIRO_DOCK_BUILDLINK3_MK)
CAIRO_DOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairo-dock+=	cairo-dock>=3.2.1
BUILDLINK_PKGSRCDIR.cairo-dock?=	../../wip/cairo-dock

#.include "../../graphics/cairo/buildlink3.mk"
#.include "../../graphics/gtkglext/buildlink3.mk"
#.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#.include "../../x11/libXtst/buildlink3.mk"
#.include "../../x11/libXxf86vm/buildlink3.mk"
.endif	# CAIRO_DOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairo-dock
