# $NetBSD: buildlink3.mk,v 1.2 2014/05/15 21:49:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-network-conduit

.if !defined(HS_NETWORK_CONDUIT_BUILDLINK3_MK)
HS_NETWORK_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-conduit+=	hs-network-conduit>=1.0.0
BUILDLINK_PKGSRCDIR.hs-network-conduit?=	../../wip/hs-network-conduit

.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_NETWORK_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-conduit
