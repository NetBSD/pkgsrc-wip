# $NetBSD: buildlink3.mk,v 1.4 2011/03/03 01:45:43 phonohawk Exp $

BUILDLINK_TREE+=	hs-parsec

.if !defined(HS_PARSEC_BUILDLINK3_MK)
HS_PARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parsec+=	hs-parsec>=3.1
BUILDLINK_PKGSRCDIR.hs-parsec?=	../../wip/hs-parsec

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_PARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parsec
