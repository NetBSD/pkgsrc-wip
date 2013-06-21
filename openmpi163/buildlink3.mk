# $NetBSD: buildlink3.mk,v 1.3 2013/06/21 18:56:28 outpaddling Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi163

MPI_PREFIX?=	$(BUILDLINK_PREFIX.openmpi)
FIND_PREFIX:=	BUILDLINK_PREFIX.openmpi=openmpi

# Make sure dependent ports use correct MPI compiler wrappers
PREPEND_PATH+=	$(MPI_PREFIX)/bin

.include "../../mk/find-prefix.mk"

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
