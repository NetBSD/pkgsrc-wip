# $NetBSD: buildlink3.mk,v 1.1 2013/03/10 13:58:15 othyro Exp $

BUILDLINK_TREE+=	soil

.if !defined(SOIL_BUILDLINK3_MK)
SOIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soil+=	soil>=20080707
BUILDLINK_PKGSRCDIR.soil?=	../../wip/soil

.include "../../graphics/MesaLib/buildlink3.mk"
.endif	# SOIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-soil
