# $NetBSD$

BUILDLINK_TREE+=	xapp

.if !defined(XAPP_BUILDLINK3_MK)
XAPP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xapp?=	build

BUILDLINK_API_DEPENDS.xapp+=	xapp>=2.4.1
BUILDLINK_PKGSRCDIR.xapp?=	../../category/xapps

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.endif	# XAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapp
