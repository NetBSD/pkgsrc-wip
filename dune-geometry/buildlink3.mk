# $NetBSD: buildlink3.mk,v 1.1 2012/09/15 23:59:12 jihbed Exp $

BUILDLINK_TREE+=	dune-geometry

.if !defined(DUNE_GEOMETRY_BUILDLINK3_MK)
DUNE_GEOMETRY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dune-geometry+=	dune-geometry>=2.2.0
BUILDLINK_PKGSRCDIR.dune-geometry?=	../../wip/dune-geometry

#.include "../../wip/dune-common/buildlink3.mk"
#.include "../../devel/gmp/buildlink3.mk"
#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../mk/blas.buildlink3.mk"
.endif	# DUNE_GEOMETRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-dune-geometry
