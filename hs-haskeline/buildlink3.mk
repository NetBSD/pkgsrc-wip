# $NetBSD: buildlink3.mk,v 1.6 2010/01/24 03:42:27 phonohawk Exp $

BUILDLINK_TREE+=	hs-haskeline

.if !defined(HS_HASKELINE_BUILDLINK3_MK)
HS_HASKELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskeline+=	hs-haskeline>=0.6.2.1
BUILDLINK_PKGSRCDIR.hs-haskeline?=	../../wip/hs-haskeline

.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.endif	# HS_HASKELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskeline
