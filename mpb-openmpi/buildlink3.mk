# $NetBSD: buildlink3.mk,v 1.1 2013/06/23 18:33:44 outpaddling Exp $
# XXX	BUILDLINK_DEPMETHOD.mpb-openmpi?=	build

BUILDLINK_TREE+=	mpb-openmpi

.if !defined(MPB_BUILDLINK3_MK)
MPB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpb-openmpi+=	mpb-openmpi>=1.4.2
BUILDLINK_PKGSRCDIR.mpb-openmpi?=	../../jb-wip/mpb-openmpi

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../wip/libctl/buildlink3.mk"
.endif	# MPB_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpb-openmpi
