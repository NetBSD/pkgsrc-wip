# $NetBSD: buildlink3.mk,v 1.3 2011/02/17 21:01:41 zecrazytux Exp $

BUILDLINK_TREE+=	discount

.if !defined(DISCOUNT_BUILDLINK3_MK)
DISCOUNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.discount+=	discount>=2.0.1
BUILDLINK_PKGSRCDIR.discount?=		../../wip/discount
.endif	# DISCOUNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-discount
