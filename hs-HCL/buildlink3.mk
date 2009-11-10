# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/10 03:35:09 phonohawk Exp $

BUILDLINK_TREE+=	hs-HCL

.if !defined(HS_HCL_BUILDLINK3_MK)
HS_HCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HCL+=	hs-HCL>=1.4
BUILDLINK_PKGSRCDIR.hs-HCL?=	../../wip/hs-HCL

.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_HCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HCL
