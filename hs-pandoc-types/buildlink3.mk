# $NetBSD: buildlink3.mk,v 1.7 2014/09/07 21:10:04 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pandoc-types

.if !defined(HS_PANDOC_TYPES_BUILDLINK3_MK)
HS_PANDOC_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.12.3
BUILDLINK_ABI_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.12.3.2
BUILDLINK_PKGSRCDIR.hs-pandoc-types?=	../../wip/hs-pandoc-types

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_PANDOC_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-types
