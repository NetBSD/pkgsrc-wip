# $NetBSD: buildlink3.mk,v 1.6 2007/01/23 06:18:48 bsadewitz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSM_BUILDLINK3_MK:=	${LIBSM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libSM
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibSM}
BUILDLINK_PACKAGES+=	libSM
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libSM

.if ${LIBSM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libSM+=	libSM>=1.0.2
BUILDLINK_PKGSRCDIR.libSM?=	../../wip/libSM
.endif	# LIBSM_BUILDLINK3_MK

.include "../../wip/libICE/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
