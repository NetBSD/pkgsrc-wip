# $NetBSD$

BUILDLINK_TREE+=	cblas-ng

.if !defined(CBLAS_NG_BUILDLINK3_MK)
CBLAS_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas-ng+=	cblas-ng>=3.8.0
BUILDLINK_PKGSRCDIR.cblas-ng?=	../../wip/cblas-ng
.endif

BUILDLINK_TREE+=	-cblas-ng
