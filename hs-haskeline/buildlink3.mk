# $NetBSD: buildlink3.mk,v 1.11 2014/08/29 14:10:15 szptvlfn Exp $

BUILDLINK_TREE+=	hs-haskeline

.if !defined(HS_HASKELINE_BUILDLINK3_MK)
HS_HASKELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskeline+=	hs-haskeline>=0.7.1
BUILDLINK_ABI_DEPENDS.hs-haskeline+=	hs-haskeline>=0.7.1.3
BUILDLINK_PKGSRCDIR.hs-haskeline?=	../../wip/hs-haskeline

.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_HASKELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskeline
