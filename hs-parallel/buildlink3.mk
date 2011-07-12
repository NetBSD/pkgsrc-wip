# $NetBSD: buildlink3.mk,v 1.5 2011/07/12 14:26:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-parallel

.if !defined(HS_PARALLEL_BUILDLINK3_MK)
HS_PARALLEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parallel+=	hs-parallel>=3.1
BUILDLINK_PKGSRCDIR.hs-parallel?=	../../wip/hs-parallel

.include "../../wip/hs-deepseq/buildlink3.mk"
.endif	# HS_PARALLEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel
