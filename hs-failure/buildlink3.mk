# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/12/02 04:56:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-failure

.if !defined(HS_FAILURE_BUILDLINK3_MK)
HS_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-failure+=	hs-failure>=0.1.0
BUILDLINK_PKGSRCDIR.hs-failure?=	../../wip/hs-failure
.endif	# HS_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-failure
