# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/23 22:31:06 jihbed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GECKO_SHARP_2.0_BUILDLINK3_MK:=	${GECKO_SHARP_2.0_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gecko-sharp-2.0
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngecko-sharp-2.0}
BUILDLINK_PACKAGES+=	gecko-sharp-2.0
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gecko-sharp-2.0

.if ${GECKO_SHARP_2.0_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gecko-sharp-2.0+=		gecko-sharp>=2.0
BUILDLINK_PKGSRCDIR.gecko-sharp-2.0?=	../../wip/gecko-sharp
.endif	# GECKO_SHARP_2.0_BUILDLINK3_MK

.include "../../x11/gtk-sharp/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
