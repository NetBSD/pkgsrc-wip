# $NetBSD: buildlink3.mk,v 1.8 2014/05/08 00:29:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mtl

.if !defined(HS_MTL_BUILDLINK3_MK)
HS_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mtl+=	hs-mtl>=2.2.0
BUILDLINK_PKGSRCDIR.hs-mtl?=	../../wip/hs-mtl

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mtl
