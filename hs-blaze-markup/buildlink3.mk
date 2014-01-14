# $NetBSD: buildlink3.mk,v 1.3 2014/01/14 21:20:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-markup

.if !defined(HS_BLAZE_MARKUP_BUILDLINK3_MK)
HS_BLAZE_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-markup+=	hs-blaze-markup>=0.5.2
BUILDLINK_PKGSRCDIR.hs-blaze-markup?=	../../wip/hs-blaze-markup

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-markup
