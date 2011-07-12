# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 05:06:10 phonohawk Exp $

BUILDLINK_TREE+=	hs-fclabels

.if !defined(HS_FCLABELS_BUILDLINK3_MK)
HS_FCLABELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fclabels+=	hs-fclabels>=0.11
BUILDLINK_PKGSRCDIR.hs-fclabels?=	../../wip/hs-fclabels

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_FCLABELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fclabels
