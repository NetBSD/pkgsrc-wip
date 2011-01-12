# $NetBSD: buildlink3.mk,v 1.2 2011/01/12 02:40:24 phonohawk Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=0.11
BUILDLINK_PKGSRCDIR.hs-text?=	../../wip/hs-text

.include "../../wip/hs-deepseq/buildlink3.mk"
.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
