# $NetBSD: buildlink3.mk,v 1.2 2013/06/21 17:26:49 outpaddling Exp $

BUILDLINK_TREE+=	openmpi163

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi163

MPI_PREFIX?=	$(BUILDLINK_PREFIX.openmpi)
FIND_PREFIX:=	BUILDLINK_PREFIX.openmpi=openmpi
PREPEND_PATH+=	$(MPI_PREFIX)/bin

.include "../../mk/find-prefix.mk"

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi163
