# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:35:24 wiz Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi

MPI_SUBPREFIX=  openmpi4
MPI_PREFIX=     ${PREFIX}/${MPI_SUBPREFIX}

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
