# $NetBSD: buildlink3.mk,v 1.5 2011/07/28 13:48:40 phonohawk Exp $

BUILDLINK_TREE+=	hs-convertible

.if !defined(HS_CONVERTIBLE_BUILDLINK3_MK)
HS_CONVERTIBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-convertible+=	hs-convertible>=1.0
BUILDLINK_PKGSRCDIR.hs-convertible?=	../../wip/hs-convertible

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_CONVERTIBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-convertible
