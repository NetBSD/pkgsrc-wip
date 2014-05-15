# $NetBSD: buildlink3.mk,v 1.4 2014/05/15 21:49:08 szptvlfn Exp $

BUILDLINK_TREE+=	hs-failure

.if !defined(HS_FAILURE_BUILDLINK3_MK)
HS_FAILURE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-failure+=	hs-failure>=0.2.0
BUILDLINK_PKGSRCDIR.hs-failure?=	../../wip/hs-failure

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_FAILURE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-failure
