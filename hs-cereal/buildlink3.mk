# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 07:13:22 phonohawk Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.3
BUILDLINK_PKGSRCDIR.hs-cereal?=	../../wip/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
