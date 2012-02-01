# $NetBSD: buildlink3.mk,v 1.3 2012/02/01 15:49:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-failure

.if !defined(HS_FAILURE_BUILDLINK3_MK)
HS_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-failure+=	hs-failure>=0.2.0
BUILDLINK_PKGSRCDIR.hs-failure?=	../../wip/hs-failure

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-failure
