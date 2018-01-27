# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-cereal+=	hs-cereal>=0.4.0.1
BUILDLINK_PKGSRCDIR.hs-cereal?=		../../wip/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
