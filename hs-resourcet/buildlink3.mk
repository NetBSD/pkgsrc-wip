# $NetBSD: buildlink3.mk,v 1.7 2014/06/28 22:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=1.1.2
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../wip/hs-resourcet

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
