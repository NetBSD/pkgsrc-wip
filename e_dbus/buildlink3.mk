# $NetBSD: buildlink3.mk,v 1.1 2012/12/30 19:57:06 roelants Exp $

BUILDLINK_TREE+=	e_dbus

.if !defined(E_DBUS_BUILDLINK3_MK)
E_DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.e_dbus+=	e_dbus>=1.7.0
BUILDLINK_PKGSRCDIR.e_dbus?=	../../wip/e_dbus

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.endif # E_DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-e_dbus
