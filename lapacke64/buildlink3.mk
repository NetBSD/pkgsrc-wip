# $NetBSD: buildlink3.mk,v 1.1 2021/04/20 20:40:47 thor Exp $

BUILDLINK_TREE+=	lapacke64

.if !defined(LAPACKE64_BUILDLINK3_MK)
LAPACKE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke64+=	lapacke64>=3.9.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../wip/lapacke64

.include	"../../wip/lapack64/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke64
