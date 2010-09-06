# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/06 14:00:15 jihbed Exp $

BUILDLINK_TREE+=	hepmc

.if !defined(HEPMC_BUILDLINK3_MK)
HEPMC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hepmc+=	hepmc>=2.06.02
BUILDLINK_PKGSRCDIR.hepmc?=	../../wip/hepmc
.endif	# HEPMC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hepmc
