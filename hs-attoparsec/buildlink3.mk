# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-attoparsec

.if !defined(HS_ATTOPARSEC_BUILDLINK3_MK)
HS_ATTOPARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.11.1
BUILDLINK_ABI_DEPENDS.hs-attoparsec+=	hs-attoparsec>=0.11.1.0
BUILDLINK_PKGSRCDIR.hs-attoparsec?=	../../wip/hs-attoparsec

.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_ATTOPARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-attoparsec
