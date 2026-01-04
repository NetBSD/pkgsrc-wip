# $NetBSD: buildlink3.mk,v 1.2 2018/03/10 05:37:44 schmonz Exp $

BUILDLINK_TREE+=	discount

.if !defined(DISCOUNT_BUILDLINK3_MK)
DISCOUNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.discount+=	discount>=3
BUILDLINK_PKGSRCDIR.discount?=		../../wip/discount3
.endif	# DISCOUNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-discount
