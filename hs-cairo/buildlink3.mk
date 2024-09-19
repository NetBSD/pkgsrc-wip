# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cairo

.if !defined(HS_CAIRO_BUILDLINK3_MK)
HS_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cairo+=	hs-cairo>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-cairo+=	hs-cairo>=0.12.3
BUILDLINK_PKGSRCDIR.hs-cairo?=		../../wip/hs-cairo

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cairo
