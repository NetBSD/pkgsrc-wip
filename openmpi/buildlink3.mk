# $NetBSD: buildlink3.mk,v 1.7 2013/06/21 17:07:52 outpaddling Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/openmpi/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/openmpi/lib

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
