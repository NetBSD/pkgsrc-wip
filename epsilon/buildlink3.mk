# $NetBSD: buildlink3.mk,v 1.5 2009/03/04 17:47:47 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPSILON_BUILDLINK3_MK:=	${EPSILON_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	epsilon
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nepsilon}
BUILDLINK_PACKAGES+=	epsilon
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}epsilon

.if ${EPSILON_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.epsilon+=	epsilon>=0.3.0.012
BUILDLINK_ABI_DEPENDS.epsilon?=	epsilon>=0.3.0.012nb1
BUILDLINK_PKGSRCDIR.epsilon?=	../../wip/epsilon
.endif	# EPSILON_BUILDLINK3_MK

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epeg/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
