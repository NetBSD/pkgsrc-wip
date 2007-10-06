# $NetBSD: buildlink3.mk,v 1.1 2007/10/06 22:45:13 othyro Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TWINKLE_BUILDLINK3_MK:=	${TWINKLE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	twinkle
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntwinkle}
BUILDLINK_PACKAGES+=	twinkle
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}twinkle

.if ${TWINKLE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.twinkle+=	twinkle>=1.1
BUILDLINK_PKGSRCDIR.twinkle?=	../../wip/twinkle
.endif	# TWINKLE_BUILDLINK3_MK

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
