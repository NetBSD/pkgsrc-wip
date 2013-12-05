# $NetBSD: buildlink3.mk,v 1.7 2013/12/05 03:05:29 phonohawk Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=1.0.0
BUILDLINK_PKGSRCDIR.hs-text?=	../../wip/hs-text

.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
