# $NetBSD: buildlink3.mk,v 1.1 2021/04/20 20:37:03 thor Exp $

BUILDLINK_TREE+=	cblas64

.if !defined(CBLAS64_BUILDLINK3_MK)
CBLAS64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas64+=	cblas64>=3.9.0
BUILDLINK_PKGSRCDIR.cblas64?=	../../wip/cblas64

.include	"../../wip/blas64/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-cblas64
