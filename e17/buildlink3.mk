# $NetBSD: buildlink3.mk,v 1.5 2008/10/20 00:09:22 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
E17_BUILDLINK3_MK:=	${E17_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	e17
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ne17}
BUILDLINK_PACKAGES+=	e17
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}e17

.if ${E17_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.e17+=	e17>=0.16.999.042
BUILDLINK_ABI_DEPENDS.e17?=	e17>=0.16.999.042nb1
BUILDLINK_PKGSRCDIR.e17?=	../../wip/e17
.endif	# E17_BUILDLINK3_MK

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
