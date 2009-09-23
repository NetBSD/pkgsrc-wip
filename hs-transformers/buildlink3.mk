# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 05:12:01 phonohawk Exp $

BUILDLINK_TREE+=	hs-transformers

.if !defined(HS_TRANSFORMERS_BUILDLINK3_MK)
HS_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers+=	hs-transformers>=0.1.4.0
BUILDLINK_PKGSRCDIR.hs-transformers?=	../../wip/hs-transformers
.endif	# HS_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers
