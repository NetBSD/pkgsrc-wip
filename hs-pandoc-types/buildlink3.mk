# $NetBSD: buildlink3.mk,v 1.2 2013/09/19 10:37:33 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pandoc-types

.if !defined(HS_PANDOC_TYPES_BUILDLINK3_MK)
HS_PANDOC_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-types+=	hs-pandoc-types>=1.12.1
BUILDLINK_PKGSRCDIR.hs-pandoc-types?=	../../wip/hs-pandoc-types

.include "../../wip/hs-aeson/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.endif	# HS_PANDOC_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-types
