# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/30 05:04:54 phonohawk Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.9
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../wip/hs-attoparsec

.include "../../wip/hs-deepseq/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
