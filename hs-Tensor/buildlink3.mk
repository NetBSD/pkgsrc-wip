# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/22 14:01:20 phonohawk Exp $

BUILDLINK_TREE+=	hs-Tensor

.if !defined(HS_TENSOR_BUILDLINK3_MK)
HS_TENSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Tensor+=	hs-Tensor>=1.0.0.1
BUILDLINK_PKGSRCDIR.hs-Tensor?=	../../wip/hs-Tensor
.endif	# HS_TENSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Tensor
