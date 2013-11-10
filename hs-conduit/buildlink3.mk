# $NetBSD: buildlink3.mk,v 1.3 2013/11/10 09:53:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-conduit

.if !defined(HS_CONDUIT_BUILDLINK3_MK)
HS_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-conduit+=	hs-conduit>=1.0.9
BUILDLINK_PKGSRCDIR.hs-conduit?=	../../wip/hs-conduit

.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../wip/hs-mmorph/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-resourcet/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.include "../../wip/hs-void/buildlink3.mk"
.endif	# HS_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-conduit
