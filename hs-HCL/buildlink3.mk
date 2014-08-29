# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HCL

.if !defined(HS_HCL_BUILDLINK3_MK)
HS_HCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HCL+=	hs-HCL>=1.4
BUILDLINK_ABI_DEPENDS.hs-HCL+=	hs-HCL>=1.4
BUILDLINK_PKGSRCDIR.hs-HCL?=	../../wip/hs-HCL

.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_HCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HCL
