# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	edbus

.if !defined(EDBUS_BUILDLINK3_MK)
EDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edbus+=	edbus>=0.01
BUILDLINK_PKGSRCDIR.edbus?=	../../wip/edbus
.endif # EDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-edbus
