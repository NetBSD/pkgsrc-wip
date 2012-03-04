# $NetBSD: buildlink3.mk,v 1.3 2012/03/04 05:05:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.10.1
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../wip/hs-attoparsec

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
