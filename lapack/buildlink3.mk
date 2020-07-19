# $NetBSD$

BUILDLINK_TREE+=	lapack

.if !defined(LAPACK_BUILDLINK3_MK)
LAPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack+=	lapack>=3.9.0
BUILDLINK_ABI_DEPENDS.lapack+=	lapack>=3.9.0
BUILDLINK_PKGSRCDIR.lapack?=	../../wip/lapack

.include "../../wip/blas/buildlink3.mk"

.endif # LAPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack
