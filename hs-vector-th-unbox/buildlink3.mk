# $NetBSD: buildlink3.mk,v 1.1 2013/02/27 12:24:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-vector-th-unbox

.if !defined(HS_VECTOR_TH_UNBOX_BUILDLINK3_MK)
HS_VECTOR_TH_UNBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-th-unbox+=	hs-vector-th-unbox>=0.2.0
BUILDLINK_PKGSRCDIR.hs-vector-th-unbox?=	../../wip/hs-vector-th-unbox

.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_TH_UNBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-th-unbox
