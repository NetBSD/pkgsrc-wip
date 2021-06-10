# $NetBSD: buildlink3.mk,v 1.2 2020/11/05 17:06:10 bacon Exp $

BUILDLINK_TREE+=	openblas64_openmp

.if !defined(OPENBLAS64_OPENMP_BUILDLINK3_MK)
OPENBLAS64_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openblas64_openmp+=	openblas64_openmp>=0.3.5
BUILDLINK_PKGSRCDIR.openblas64_openmp?=		../../wip/openblas64_openmp
.endif	# OPENBLAS64_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-openblas64_openmp
