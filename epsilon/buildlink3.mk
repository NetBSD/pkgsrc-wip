# $NetBSD: buildlink3.mk,v 1.2 2008/01/18 04:30:12 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPSILON_BUILDLINK3_MK:=	${EPSILON_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	epsilon
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nepsilon}
BUILDLINK_PACKAGES+=	epsilon
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}epsilon

.if ${EPSILON_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.epsilon+=	epsilon>=0.3.0.011
BUILDLINK_ABI_DEPENDS.epsilon?=	epsilon>=0.3.0.011nb1
BUILDLINK_PKGSRCDIR.epsilon?=	../../wip/epsilon
.endif	# EPSILON_BUILDLINK3_MK

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epeg/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
