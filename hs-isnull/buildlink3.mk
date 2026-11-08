# $NetBSD$

BUILDLINK_TREE+=	hs-isnull

.if !defined(HS_ISNULL_BUILDLINK3_MK)
HS_ISNULL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-isnull+=	hs-isnull>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-isnull+=	hs-isnull>=0.4.0.0
BUILDLINK_PKGSRCDIR.hs-isnull?=		../../wip/hs-isnull

.endif	# HS_ISNULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-isnull
