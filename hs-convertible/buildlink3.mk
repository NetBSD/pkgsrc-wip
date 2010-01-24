# $NetBSD: buildlink3.mk,v 1.3 2010/01/24 03:34:19 phonohawk Exp $

BUILDLINK_TREE+=	hs-convertible

.if !defined(HS_CONVERTIBLE_BUILDLINK3_MK)
HS_CONVERTIBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-convertible+=	hs-convertible>=1.0.5
BUILDLINK_PKGSRCDIR.hs-convertible?=	../../wip/hs-convertible

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_CONVERTIBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-convertible
