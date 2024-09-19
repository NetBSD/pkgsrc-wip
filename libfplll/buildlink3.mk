# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/03 22:58:42 jihbed Exp $

BUILDLINK_TREE+=	libfplll

.if !defined(LIBFPLLL_BUILDLINK3_MK)
LIBFPLLL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfplll+=	libfplll>=3.0.12
BUILDLINK_PKGSRCDIR.libfplll?=		../../wip/libfplll


.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.endif	# LIBFPLLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfplll
