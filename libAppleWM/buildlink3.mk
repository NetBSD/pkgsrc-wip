# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/05 17:10:59 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBAPPLEWM_BUILDLINK3_MK:=	${LIBAPPLEWM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libAppleWM
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibAppleWM}
BUILDLINK_PACKAGES+=	libAppleWM
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libAppleWM

.if ${LIBAPPLEWM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libAppleWM+=	libAppleWM>=1.2.0
BUILDLINK_PKGSRCDIR.libAppleWM?=	../../wip/libAppleWM
.endif	# LIBAPPLEWM_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../wip/applewmproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
