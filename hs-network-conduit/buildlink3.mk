# $NetBSD: buildlink3.mk,v 1.4 2014/07/30 21:36:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-network-conduit

.if !defined(HS_NETWORK_CONDUIT_BUILDLINK3_MK)
HS_NETWORK_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network-conduit+=	hs-network-conduit>=1.0.0
BUILDLINK_PKGSRCDIR.hs-network-conduit?=	../../wip/hs-network-conduit

.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_NETWORK_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network-conduit
