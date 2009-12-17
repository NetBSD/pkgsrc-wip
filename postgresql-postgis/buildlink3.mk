# $NetBSD: buildlink3.mk,v 1.2 2009/12/17 10:17:47 moubctez Exp $

BUILDLINK_TREE+=	postgresql84-postgis

.if !defined(POSTGRESQL84_POSTGIS_BUILDLINK3_MK)
POSTGRESQL84_POSTGIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql84-postgis+=	postgresql84-postgis>=1.4
BUILDLINK_PKGSRCDIR.postgresql84-postgis?=	../../wip/postgresql-postgis

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.endif	# POSTGRESQL84_POSTGIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql84-postgis
