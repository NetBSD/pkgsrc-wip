# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 03:58:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-MonadCatchIO-mtl

.if !defined(HS_MONADCATCHIO_MTL_BUILDLINK3_MK)
HS_MONADCATCHIO_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadCatchIO-mtl+=	hs-MonadCatchIO-mtl>=0.3
BUILDLINK_PKGSRCDIR.hs-MonadCatchIO-mtl?=	../../wip/hs-MonadCatchIO-mtl

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_MONADCATCHIO_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadCatchIO-mtl
