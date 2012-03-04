# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 07:59:16 phonohawk Exp $

BUILDLINK_TREE+=	hs-cereal

.if !defined(HS_CEREAL_BUILDLINK3_MK)
HS_CEREAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cereal+=	hs-cereal>=0.3.5
BUILDLINK_PKGSRCDIR.hs-cereal?=	../../wip/hs-cereal
.endif	# HS_CEREAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cereal
