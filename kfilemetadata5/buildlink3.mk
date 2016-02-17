# $NetBSD$

BUILDLINK_TREE+=	kfilemetadata5

.if !defined(KFILEMETADATA5_BUILDLINK3_MK)
KFILEMETADATA5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kfilemetadata5+=	kfilemetadata5>=5.19.0
BUILDLINK_PKGSRCDIR.kfilemetadata5?=	../../wip/kfilemetadata5

.endif	# KFILEMETADATA5_BUILDLINK3_MK

BUILDLINK_TREE+=	-kfilemetadata5
