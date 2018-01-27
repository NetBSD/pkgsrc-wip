# $NetBSD$

BUILDLINK_TREE+=	openblas

.if !defined(OPENBLAS_BUILDLINK3_MK)
OPENBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas+=	openblas>=0.2.20
BUILDLINK_PKGSRCDIR.openblas?=		../../wip/openblas-devel
.endif	# OPENBLAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas
