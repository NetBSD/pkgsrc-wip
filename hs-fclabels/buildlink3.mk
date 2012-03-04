# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 07:06:36 phonohawk Exp $

BUILDLINK_TREE+=	hs-fclabels

.if !defined(HS_FCLABELS_BUILDLINK3_MK)
HS_FCLABELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fclabels+=	hs-fclabels>=1.0.4
BUILDLINK_PKGSRCDIR.hs-fclabels?=	../../wip/hs-fclabels

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_FCLABELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fclabels
