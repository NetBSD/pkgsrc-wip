# $NetBSD: buildlink3.mk,v 1.2 2011/07/12 10:00:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-cairo

.if !defined(HS_CAIRO_BUILDLINK3_MK)
HS_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cairo+=	hs-cairo>=0.12
BUILDLINK_PKGSRCDIR.hs-cairo?=	../../wip/hs-cairo

.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cairo
