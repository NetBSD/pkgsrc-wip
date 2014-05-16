# $NetBSD: buildlink3.mk,v 1.7 2014/05/16 20:47:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-convertible

.if !defined(HS_CONVERTIBLE_BUILDLINK3_MK)
HS_CONVERTIBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-convertible+=	hs-convertible>=1.0.11
BUILDLINK_PKGSRCDIR.hs-convertible?=	../../wip/hs-convertible

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_CONVERTIBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-convertible
