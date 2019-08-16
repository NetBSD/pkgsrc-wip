# $NetBSD$

BUILDLINK_TREE+=	blas

.include "../../wip/lapack/buildlink3.mk"

BUILDLINK_TREE+=	-blas
