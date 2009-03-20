# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	mapserver

BUILDLINK_API_DEPENDS.mapserver+=	mapserver>=4.4.2
BUILDLINK_PKGSRCDIR.mapserver?=	../../wip/mapserver

.include "../../mk/x11.buildlink3.mk"
.endif # MAPSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mapserver
