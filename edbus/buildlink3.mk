# $NetBSD: buildlink3.mk,v 1.8 2010/01/18 19:37:07 jsonn Exp $

BUILDLINK_TREE+=	edbus

.if !defined(EDBUS_BUILDLINK3_MK)
EDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edbus+=	edbus>=0.5.0.063
BUILDLINK_PKGSRCDIR.edbus?=	../../wip/edbus

.include "../../sysutils/dbus/buildlink3.mk"
.endif # EDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-edbus
