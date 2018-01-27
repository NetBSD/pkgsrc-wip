# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-control-monad-failure

.if !defined(HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK)
HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-control-monad-failure+=	hs-control-monad-failure>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-control-monad-failure+=	hs-control-monad-failure>=0.7.0
BUILDLINK_PKGSRCDIR.hs-control-monad-failure?=		../../wip/hs-control-monad-failure

.include "../../wip/hs-failure/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-control-monad-failure
