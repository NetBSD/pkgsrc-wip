# $NetBSD: buildlink3.mk,v 1.4 2013/01/15 09:18:41 phonohawk Exp $

BUILDLINK_TREE+=	hs-vector

.if !defined(HS_VECTOR_BUILDLINK3_MK)
HS_VECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector+=	hs-vector>=0.10
BUILDLINK_PKGSRCDIR.hs-vector?=	../../wip/hs-vector

.include "../../wip/hs-primitive/buildlink3.mk"
.endif	# HS_VECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector
