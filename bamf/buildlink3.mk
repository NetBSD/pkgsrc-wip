# $NetBSD$


BUILDLINK_TREE+=	bamf

.if !defined(BAMF_BUILDLINK3_MK)
BAMF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bamf+=	bamf>=0.5.4
BUILDLINK_PKGSRCDIR.bamf?=	../../wip/bamf

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# BAMF_BUILDLINK3_MK

BUILDLINK_TREE+=	-bamf
