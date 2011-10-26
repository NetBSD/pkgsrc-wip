# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/26 22:55:34 phonohawk Exp $

BUILDLINK_TREE+=	hs-stringsearch

.if !defined(HS_STRINGSEARCH_BUILDLINK3_MK)
HS_STRINGSEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringsearch+=	hs-stringsearch>=0.3.6
BUILDLINK_PKGSRCDIR.hs-stringsearch?=	../../wip/hs-stringsearch
.endif	# HS_STRINGSEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringsearch
