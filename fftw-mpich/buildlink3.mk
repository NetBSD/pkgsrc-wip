# $NetBSD: buildlink3.mk,v 1.1 2013/06/23 18:22:25 outpaddling Exp $

BUILDLINK_TREE+=	fftw-openmpi

.if !defined(FFTW_BUILDLINK3_MK)
FFTW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fftw-openmpi+=	fftw-openmpi>=3.0
BUILDLINK_ABI_DEPENDS.fftw-openmpi+=	fftw-openmpi>=3.1nb1
BUILDLINK_PKGSRCDIR.fftw-openmpi?=	../../wip/fftw-openmpi

.include "../../wip/openmpi-prefixed/buildlink3.mk"
.endif # FFTW_BUILDLINK3_MK

BUILDLINK_TREE+=	-fftw-openmpi
