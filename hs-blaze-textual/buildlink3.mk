# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-textual

.if !defined(HS_BLAZE_TEXTUAL_BUILDLINK3_MK)
HS_BLAZE_TEXTUAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-blaze-textual+=	hs-blaze-textual>=0.2.0.8
BUILDLINK_PKGSRCDIR.hs-blaze-textual?=		../../wip/hs-blaze-textual

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_BLAZE_TEXTUAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-textual
