# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	blis_openmp

.if !defined(BLIS_OPENMP_BUILDLINK3_MK)
BLIS_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blis_openmp+=	blis_openmp>=0.9.0
BUILDLINK_ABI_DEPENDS.blis_openmp+=	blis_openmp>=0.9.0
BUILDLINK_PKGSRCDIR.blis_openmp?=	../../wip/blis_openmp
.endif # BLIS_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-blis_openmp
