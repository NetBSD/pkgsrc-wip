# $NetBSD: buildlink3.mk,v 1.4 2013/10/20 16:15:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pandoc-types

.if !defined(HS_PANDOC_TYPES_BUILDLINK3_MK)
HS_PANDOC_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.12.3
BUILDLINK_PKGSRCDIR.hs-pandoc-types?=	../../wip/hs-pandoc-types

.include "../../wip/hs-aeson/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.endif	# HS_PANDOC_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-types
