# $NetBSD: buildlink3.mk,v 1.1 2013/05/24 22:16:19 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vector-space

.if !defined(HS_VECTOR_SPACE_BUILDLINK3_MK)
HS_VECTOR_SPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-space+=	hs-vector-space>=0.8.6
BUILDLINK_PKGSRCDIR.hs-vector-space?=	../../wip/hs-vector-space

.endif	# HS_VECTOR_SPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-space
