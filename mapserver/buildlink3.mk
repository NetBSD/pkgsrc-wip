# $NetBSD: buildlink3.mk,v 1.5 2005/06/12 23:51:22 kristerw Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MAPSERVER_BUILDLINK3_MK:=	${MAPSERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mapserver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmapserver}
BUILDLINK_PACKAGES+=	mapserver

.if !empty(MAPSERVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mapserver+=	mapserver>=4.4.2
BUILDLINK_PKGSRCDIR.mapserver?=	../../wip/mapserver
.endif	# MAPSERVER_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
