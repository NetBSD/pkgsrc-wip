# $NetBSD$

BUILDLINK_TREE+=	lapacke-ng

.if !defined(LAPACKE_NG_BUILDLINK3_MK)
LAPACKE_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke-ng+=	lapacke-ng>=3.8.0
BUILDLINK_PKGSRCDIR.lapacke-ng?=	../../wip/lapacke-ng

.include	"../../wip/mk/blas.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke-ng
