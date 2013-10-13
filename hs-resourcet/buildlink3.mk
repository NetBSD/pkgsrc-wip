# $NetBSD: buildlink3.mk,v 1.2 2013/10/13 08:23:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=0.4.9
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../wip/hs-resourcet

.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../wip/hs-mmorph/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
