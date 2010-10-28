# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/28 14:11:15 hfath Exp $

BUILDLINK_TREE+=	cgal

.if !defined(CGAL_BUILDLINK3_MK)
CGAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgal+=	cgal>=3.7
BUILDLINK_PKGSRCDIR.cgal?=	../../wip/cgal

.include "../../graphics/glu/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif # CGAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgal
