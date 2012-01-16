# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/01/16 05:49:35 phonohawk Exp $

BUILDLINK_TREE+=	hs-control-monad-failure

.if !defined(HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK)
HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-control-monad-failure+=	hs-control-monad-failure>=0.7.0
BUILDLINK_PKGSRCDIR.hs-control-monad-failure?=	../../wip/hs-control-monad-failure

.include "../../wip/hs-failure/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_CONTROL_MONAD_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-control-monad-failure
