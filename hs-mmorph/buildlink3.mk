# $NetBSD: buildlink3.mk,v 1.2 2014/01/01 08:01:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.1
BUILDLINK_PKGSRCDIR.hs-mmorph?=	../../wip/hs-mmorph

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
