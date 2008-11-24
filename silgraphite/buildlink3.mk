# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/24 08:10:14 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SILGRAPHITE_BUILDLINK3_MK:=	${SILGRAPHITE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	silgraphite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsilgraphite}
BUILDLINK_PACKAGES+=	silgraphite
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}silgraphite

.if ${SILGRAPHITE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.silgraphite+=	silgraphite>=2.3
BUILDLINK_PKGSRCDIR.silgraphite?=	../../wip/silgraphite
.endif	# SILGRAPHITE_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
