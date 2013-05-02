# $NetBSD: buildlink3.mk,v 1.6 2013/05/02 17:33:14 asau Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi

MPI_PREFIX?=	$(BUILDLINK_PREFIX.openmpi)
FIND_PREFIX:=	BUILDLINK_PREFIX.openmpi=openmpi
.include "../../mk/find-prefix.mk"

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
