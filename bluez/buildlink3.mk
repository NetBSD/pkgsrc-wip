# $NetBSD$

BUILDLINK_TREE+=	bluez

.if !defined(BLUEZ_BUILDLINK3_MK)
BLUEZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bluez+=	bluez>=5.0
BUILDLINK_PKGSRCDIR.bluez?=	../../wip/bluez

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # BLUEZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-bluez
