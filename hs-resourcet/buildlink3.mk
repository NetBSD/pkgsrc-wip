# $NetBSD: buildlink3.mk,v 1.8 2014/07/30 21:36:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=1.1.2
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../wip/hs-resourcet

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
