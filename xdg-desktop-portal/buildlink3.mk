# $NetBSD$

BUILDLINK_TREE+=	xdg-desktop-portal

.if !defined(XDG_DESKTOP_PORTAL_BUILDLINK3_MK)
XDG_DESKTOP_PORTAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xdg-desktop-portal+=	xdg-desktop-portal>=1.20.3
BUILDLINK_PKGSRCDIR.xdg-desktop-portal?=	../../wip/xdg-desktop-portal

#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libportal/buildlink3.mk"
#.include "../../geography/geoclue/buildlink3.mk"
#.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
#.include "../../wip/pipewire/buildlink3.mk"
#.include "../../textproc/json-glib/buildlink3.mk"
.endif	# XDG_DESKTOP_PORTAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xdg-desktop-portal
