# $NetBSD: buildlink3.mk,v 1.3 2013/01/15 11:49:55 phonohawk Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.3
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../wip/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
