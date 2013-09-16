# $NetBSD: buildlink3.mk,v 1.1 2013/09/16 23:03:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.0
BUILDLINK_PKGSRCDIR.hs-mmorph?=	../../wip/hs-mmorph

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
