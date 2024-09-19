# $NetBSD: buildlink3.mk,v 1.2 2013/06/23 18:31:35 outpaddling Exp $
# BUILDLINK_DEPMETHOD.fftw2-openmpi?=	build

BUILDLINK_TREE+=	fftw2-openmpi

.if !defined(FFTW2_OPENMPI_BUILDLINK3_MK)
FFTW2_OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw2-openmpi+=	fftw2-openmpi>=2.1.5
BUILDLINK_PKGSRCDIR.fftw2-openmpi?=	../../wip/fftw2-openmpi

.include "../../wip/openmpi163/buildlink3.mk"
.endif	# FFTW2_OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw2-openmpi
