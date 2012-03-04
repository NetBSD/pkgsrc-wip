# $NetBSD: buildlink3.mk,v 1.4 2012/03/04 05:01:49 phonohawk Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=0.11.1
BUILDLINK_PKGSRCDIR.hs-text?=	../../wip/hs-text

.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
