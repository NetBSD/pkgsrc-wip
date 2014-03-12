# $NetBSD: buildlink3.mk,v 1.1 2014/03/12 23:18:50 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-algorithms

.if !defined(HS_VECTOR_ALGORITHMS_BUILDLINK3_MK)
HS_VECTOR_ALGORITHMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-algorithms+=	hs-vector-algorithms>=0.6.0
BUILDLINK_PKGSRCDIR.hs-vector-algorithms?=	../../wip/hs-vector-algorithms

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-mwc-random/buildlink3.mk"
.include "../../wip/hs-primitive/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_ALGORITHMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-algorithms
