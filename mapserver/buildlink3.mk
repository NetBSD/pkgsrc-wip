# $NetBSD: buildlink3.mk,v 1.8 2009/05/06 10:03:40 cheusov Exp $

BUILDLINK_TREE+=	mapserver

.if !defined(MAPSERVER_BUILDLINK3_MK)
MAPSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mapserver+=	mapserver>=4.4.2
BUILDLINK_PKGSRCDIR.mapserver?=	../../wip/mapserver

.include "../../mk/x11.buildlink3.mk"
.endif # MAPSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mapserver
