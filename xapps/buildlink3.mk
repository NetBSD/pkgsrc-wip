# $NetBSD$

BUILDLINK_TREE+=	xapps

.if !defined(XAPPS_BUILDLINK3_MK)
XAPPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapps+=	xapps>=1.8.9
BUILDLINK_PKGSRCDIR.xapps?=	../../wip/xapps

.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif	# XAPPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapps
