# $NetBSD: buildlink3.mk,v 1.1.1.3 2008/08/06 18:11:35 yazzy Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EWL_BUILDLINK3_MK:=	${EWL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ewl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Newl}
BUILDLINK_PACKAGES+=	ewl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ewl

.if ${EWL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ewl+=	ewl>=0.5.2.042
BUILDLINK_ABI_DEPENDS.ewl?=	ewl>=0.5.2.042nb1
BUILDLINK_PKGSRCDIR.ewl?=	../../wip/ewl
.endif	# EWL_BUILDLINK3_MK

.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
