# $NetBSD: buildlink3.mk,v 1.1 2011/07/12 10:20:34 phonohawk Exp $

BUILDLINK_TREE+=	hs-pango

.if !defined(HS_PANGO_BUILDLINK3_MK)
HS_PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pango+=	hs-pango>=0.12
BUILDLINK_PKGSRCDIR.hs-pango?=	../../wip/hs-pango

.include "../../devel/pango/buildlink3.mk"
.include "../../wip/hs-cairo/buildlink3.mk"
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pango
