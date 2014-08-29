# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-th-unbox

.if !defined(HS_VECTOR_TH_UNBOX_BUILDLINK3_MK)
HS_VECTOR_TH_UNBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-th-unbox+=	hs-vector-th-unbox>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-vector-th-unbox+=	hs-vector-th-unbox>=0.2.0.1
BUILDLINK_PKGSRCDIR.hs-vector-th-unbox?=	../../wip/hs-vector-th-unbox

.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_TH_UNBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-th-unbox
