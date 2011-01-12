# $NetBSD: buildlink3.mk,v 1.2 2011/01/12 02:34:04 phonohawk Exp $

BUILDLINK_TREE+=	hs-deepseq

.if !defined(HS_DEEPSEQ_BUILDLINK3_MK)
HS_DEEPSEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deepseq+=	hs-deepseq>=1.1
BUILDLINK_PKGSRCDIR.hs-deepseq?=	../../wip/hs-deepseq
.endif	# HS_DEEPSEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deepseq
