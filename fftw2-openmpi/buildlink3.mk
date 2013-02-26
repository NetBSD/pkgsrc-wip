# $NetBSD: buildlink3.mk,v 1.1 2013/02/26 14:52:57 outpaddling Exp $
# BUILDLINK_DEPMETHOD.fftw2-openmpi?=	build

BUILDLINK_TREE+=	fftw2-openmpi

.if !defined(FFTW2_OPENMPI_BUILDLINK3_MK)
FFTW2_OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw2-openmpi+=	fftw2-openmpi>=2.1.5
BUILDLINK_PKGSRCDIR.fftw2-openmpi?=	../../wip/fftw2-openmpi

.include "../../wip/openmpi-prefixed/buildlink3.mk"
.endif	# FFTW2_OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw2-openmpi
