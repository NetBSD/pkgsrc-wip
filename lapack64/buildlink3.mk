# $NetBSD: buildlink3.mk,v 1.10 2020/10/12 21:51:57 bacon Exp $

BUILDLINK_TREE+=	lapack64

.if !defined(LAPACK64_BUILDLINK3_MK)
LAPACK64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapack64+=	lapack64>=3.9.0
BUILDLINK_ABI_DEPENDS.lapack64+=	lapack64>=3.9.0
BUILDLINK_PKGSRCDIR.lapack64?=		../../wip/lapack64

.include "../../wip/blas64/buildlink3.mk"

.endif # LAPACK64_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapack64
