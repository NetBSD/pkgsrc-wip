# $NetBSD: buildlink3.mk,v 1.7 2014/08/29 14:10:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ascii

.if !defined(HS_ASCII_BUILDLINK3_MK)
HS_ASCII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ascii+=	hs-ascii>=0.0.4
BUILDLINK_ABI_DEPENDS.hs-ascii+=	hs-ascii>=0.0.4
BUILDLINK_PKGSRCDIR.hs-ascii?=	../../wip/hs-ascii

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_ASCII_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ascii
