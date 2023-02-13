# $NetBSD: buildlink3.mk,v 1.1 2020/11/05 16:31:45 bacon Exp $

BUILDLINK_TREE+=	libflame_openmp

.if !defined(LIBFLAME_OPENMP_BUILDLINK3_MK)
LIBFLAME_OPENMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libflame_openmp+=	libflame_openmp>=5.2.0
BUILDLINK_PKGSRCDIR.libflame_openmp?=		../../wip/libflame_openmp
.include "../../wip/blis_openmp/buildlink3.mk"
.endif	# LIBFLAME_OPENMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libflame_openmp
