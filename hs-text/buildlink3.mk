# $NetBSD: buildlink3.mk,v 1.6 2013/09/14 00:27:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-text

.if !defined(HS_TEXT_BUILDLINK3_MK)
HS_TEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text+=	hs-text>=0.11.3
BUILDLINK_PKGSRCDIR.hs-text?=	../../wip/hs-text

.endif	# HS_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text
