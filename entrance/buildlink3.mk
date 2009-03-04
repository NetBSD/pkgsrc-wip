# $NetBSD: buildlink3.mk,v 1.3 2009/03/04 17:47:47 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ENTRANCE_BUILDLINK3_MK:=	${ENTRANCE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	entrance
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nentrance}
BUILDLINK_PACKAGES+=	entrance
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}entrance

.if ${ENTRANCE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.entrance+=	entrance>=0.9.9.042nb1
BUILDLINK_PKGSRCDIR.entrance?=	../../wip/entrance
.endif	# ENTRANCE_BUILDLINK3_MK

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/esmart/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
