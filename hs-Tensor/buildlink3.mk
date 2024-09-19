# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-Tensor

.if !defined(HS_TENSOR_BUILDLINK3_MK)
HS_TENSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Tensor+=	hs-Tensor>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-Tensor+=	hs-Tensor>=1.0.0.1
BUILDLINK_PKGSRCDIR.hs-Tensor?=		../../wip/hs-Tensor
.endif	# HS_TENSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Tensor
