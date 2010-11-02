# $NetBSD: buildlink3.mk,v 1.2 2010/11/02 16:11:16 phonohawk Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.2.2.0
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../wip/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
