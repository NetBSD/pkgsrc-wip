# $NetBSD: buildlink3.mk,v 1.3 2012/10/18 01:15:20 asau Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
