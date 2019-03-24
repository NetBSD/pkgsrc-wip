# $NetBSD$

BUILDLINK_TREE+=	lapacke

.if !defined(LAPACKE_BUILDLINK3_MK)
LAPACKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke+=	lapacke-ng>=3.8.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../wip/lapacke-ng
.endif

BUILDLINK_TREE+=	-lapacke
