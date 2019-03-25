# $NetBSD$

BUILDLINK_TREE+=	lapack-ng

.if !defined(LAPACK_NG_BUILDLINK3_MK)
LAPACK_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack-ng+=	lapack-ng>=3.8.0
BUILDLINK_ABI_DEPENDS.lapack-ng+=	lapack-ng>=3.8.0
BUILDLINK_PKGSRCDIR.lapack-ng?=	../../wip/lapack-ng
.endif # LAPACK_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack-ng
