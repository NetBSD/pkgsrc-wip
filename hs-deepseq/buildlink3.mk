# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/09 03:25:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-deepseq

.if !defined(HS_DEEPSEQ_BUILDLINK3_MK)
HS_DEEPSEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deepseq+=	hs-deepseq>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-deepseq?=	../../wip/hs-deepseq
.endif	# HS_DEEPSEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deepseq
