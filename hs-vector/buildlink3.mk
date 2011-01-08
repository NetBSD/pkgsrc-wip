# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/08 04:59:25 phonohawk Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.7
BUILDLINK_PKGSRCDIR.hs-vector?=	../../wip/hs-vector

.include "../../wip/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
