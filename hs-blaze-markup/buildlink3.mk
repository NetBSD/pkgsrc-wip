# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 19:46:23 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-markup

.if !defined(HS_BLAZE_MARKUP_BUILDLINK3_MK)
HS_BLAZE_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-markup+=	hs-blaze-markup>=0.5.1.5
BUILDLINK_PKGSRCDIR.hs-blaze-markup?=	../../wip/hs-blaze-markup

.endif	# HS_BLAZE_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-markup
