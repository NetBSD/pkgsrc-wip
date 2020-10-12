# $NetBSD: buildlink3.mk,v 1.3 2013/06/23 18:44:16 outpaddling Exp $
# XXX	BUILDLINK_DEPMETHOD.mpb-openmpi?=	build

BUILDLINK_TREE+=	mpb-openmpi

.if !defined(MPB_BUILDLINK3_MK)
MPB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpb-openmpi+=	mpb-openmpi>=1.4.2
BUILDLINK_PKGSRCDIR.mpb-openmpi?=	../../wip/mpb-openmpi

.include "../../mk/blas.buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libctl/buildlink3.mk"
.endif	# MPB_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpb-openmpi
