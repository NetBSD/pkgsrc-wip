# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/02 16:46:30 phonohawk Exp $

BUILDLINK_TREE+=	hs-explicit-iomodes

.if !defined(HS_EXPLICIT_IOMODES_BUILDLINK3_MK)
HS_EXPLICIT_IOMODES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-explicit-iomodes+=	hs-explicit-iomodes>=0.5
BUILDLINK_PKGSRCDIR.hs-explicit-iomodes?=	../../wip/hs-explicit-iomodes

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_EXPLICIT_IOMODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-explicit-iomodes
