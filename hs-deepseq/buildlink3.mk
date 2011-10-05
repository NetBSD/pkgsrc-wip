# $NetBSD: buildlink3.mk,v 1.3 2011/10/05 04:38:09 phonohawk Exp $

BUILDLINK_TREE+=	hs-deepseq

.if !defined(HS_DEEPSEQ_BUILDLINK3_MK)
HS_DEEPSEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deepseq+=	hs-deepseq>=1.2
BUILDLINK_PKGSRCDIR.hs-deepseq?=	../../wip/hs-deepseq
.endif	# HS_DEEPSEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deepseq
