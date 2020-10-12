# $NetBSD: buildlink3.mk,v 1.2 2013/02/22 22:51:42 kristerw Exp $
# XXX	BUILDLINK_DEPMETHOD.mpb?=	build

BUILDLINK_TREE+=	mpb

.if !defined(MPB_BUILDLINK3_MK)
MPB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpb+=	mpb>=1.4.2
BUILDLINK_PKGSRCDIR.mpb?=	../../wip/mpb

.include "../../mk/blas.buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libctl/buildlink3.mk"
.endif	# MPB_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpb
