# $NetBSD: buildlink3.mk,v 1.5 2009/06/08 15:31:06 jsonn Exp $

BUILDLINK_TREE+=	edbus

.if !defined(EDBUS_BUILDLINK3_MK)
EDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edbus+=	edbus>=0.05
BUILDLINK_PKGSRCDIR.edbus?=	../../wip/edbus

.include "../../sysutils/dbus/buildlink3.mk"
.endif # EDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-edbus
