# $NetBSD: buildlink3.mk,v 1.5 2014/05/18 21:33:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-markup

.if !defined(HS_BLAZE_MARKUP_BUILDLINK3_MK)
HS_BLAZE_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-markup+=	hs-blaze-markup>=0.6.1
BUILDLINK_PKGSRCDIR.hs-blaze-markup?=	../../wip/hs-blaze-markup

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-markup
