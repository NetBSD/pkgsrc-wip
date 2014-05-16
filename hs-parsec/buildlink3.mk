# $NetBSD: buildlink3.mk,v 1.8 2014/05/16 20:47:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parsec

.if !defined(HS_PARSEC_BUILDLINK3_MK)
HS_PARSEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parsec+=	hs-parsec>=3.1.5
BUILDLINK_PKGSRCDIR.hs-parsec?=	../../wip/hs-parsec

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_PARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parsec
