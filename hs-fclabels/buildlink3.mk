# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-fclabels

.if !defined(HS_FCLABELS_BUILDLINK3_MK)
HS_FCLABELS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fclabels+=	hs-fclabels>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-fclabels+=	hs-fclabels>=1.0.4
BUILDLINK_PKGSRCDIR.hs-fclabels?=	../../wip/hs-fclabels

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_FCLABELS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fclabels
