# $NetBSD: buildlink3.mk,v 1.2 2012/07/02 13:37:55 moubctez Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=3.7
BUILDLINK_ABI_DEPENDS.cgal?=	cgal>=3.7nb1
BUILDLINK_PKGSRCDIR.cgal?=	../../wip/cgal

.include "../../graphics/glu/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif # CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
