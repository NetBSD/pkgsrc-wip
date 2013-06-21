# $NetBSD: buildlink3.mk,v 1.1 2013/06/21 16:40:32 outpaddling Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
# BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi
BUILDLINK_PKGSRCDIR.openmpi?=	../../jb-wip/openmpi163

MPI_PREFIX?=	$(BUILDLINK_PREFIX.openmpi)
FIND_PREFIX:=	BUILDLINK_PREFIX.openmpi=openmpi
PREPEND_PATH+=	$(MPI_PREFIX)/bin

.include "../../mk/find-prefix.mk"

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
