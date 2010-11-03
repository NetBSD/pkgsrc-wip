# $NetBSD: buildlink3.mk,v 1.1 2010/11/03 21:54:20 zecrazytux Exp $

BUILDLINK_TREE+=	discount

.if !defined(DISCOUNT_BUILDLINK3_MK)
DISCOUNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.discount+=	discount>=2.0.1
BUILDLINK_PKGSRCDIR.discount?=	../../wip/discount
.endif	# DISCOUNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-discount
