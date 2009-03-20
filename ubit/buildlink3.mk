# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	ubit

.if !defined(UBIT_BUILDLINK3_MK)
UBIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ubit+=		ubit>=5.0.0
BUILDLINK_PKGSRCDIR.ubit?=		../../wip/ubit
.endif # UBIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ubit
