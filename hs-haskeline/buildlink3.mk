# $NetBSD: buildlink3.mk,v 1.2 2009/06/05 04:41:23 phonohawk Exp $

BUILDLINK_TREE+=	hs-haskeline

.if !defined(HS_HASKELINE_BUILDLINK3_MK)
HS_HASKELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskeline+=	hs-haskeline>=0.6.1.6
BUILDLINK_PKGSRCDIR.hs-haskeline?=	../../wip/hs-haskeline

.include "../../converters/libiconv/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.endif	# HS_HASKELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskeline
