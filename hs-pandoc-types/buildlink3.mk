# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 20:37:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pandoc-types

.if !defined(HS_PANDOC_TYPES_BUILDLINK3_MK)
HS_PANDOC_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.10
BUILDLINK_PKGSRCDIR.hs-pandoc-types?=	../../wip/hs-pandoc-types

.endif	# HS_PANDOC_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-types
