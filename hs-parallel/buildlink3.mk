# $NetBSD: buildlink3.mk,v 1.4 2010/02/09 03:31:31 phonohawk Exp $

BUILDLINK_TREE+=	hs-parallel

.if !defined(HS_PARALLEL_BUILDLINK3_MK)
HS_PARALLEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parallel+=	hs-parallel>=2.2.0.1
BUILDLINK_PKGSRCDIR.hs-parallel?=	../../wip/hs-parallel

.include "../../wip/hs-deepseq/buildlink3.mk"
.endif	# HS_PARALLEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel
