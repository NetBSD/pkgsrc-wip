# $NetBSD: buildlink3.mk,v 1.4 2009/06/07 21:53:06 jsonn Exp $

BUILDLINK_TREE+=	edbus

.if !defined(EDBUS_BUILDLINK3_MK)
EDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edbus+=	edbus>=0.05
BUILDLINK_PKGSRCDIR.edbus?=	../../wip/edbus
.endif # EDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-edbus
