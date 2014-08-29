# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-space

.if !defined(HS_VECTOR_SPACE_BUILDLINK3_MK)
HS_VECTOR_SPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-space+=	hs-vector-space>=0.8.6
BUILDLINK_ABI_DEPENDS.hs-vector-space+=	hs-vector-space>=0.8.6
BUILDLINK_PKGSRCDIR.hs-vector-space?=	../../wip/hs-vector-space

.endif	# HS_VECTOR_SPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-space
