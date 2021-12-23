# $NetBSD$

BUILDLINK_TREE+=	xapp

.if !defined(XAPP_BUILDLINK3_MK)
XAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapp+=	xapp>=2.2.6
BUILDLINK_PKGSRCDIR.xapp?=	../../wip/xapps

.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif	# XAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapp
