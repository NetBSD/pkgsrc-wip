# $NetBSD: buildlink3.mk,v 1.3 2014/02/13 13:03:19 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.2
BUILDLINK_PKGSRCDIR.hs-mmorph?=	../../wip/hs-mmorph

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
