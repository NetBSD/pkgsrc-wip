# $NetBSD: buildlink3.mk,v 1.7 2007/01/23 06:16:48 bsadewitz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBICE_BUILDLINK3_MK:=	${LIBICE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libICE
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibICE}
BUILDLINK_PACKAGES+=	libICE
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libICE

.if ${LIBICE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libICE+=	libICE>=1.0.3
BUILDLINK_PKGSRCDIR.libICE?=	../../wip/libICE
.endif	# LIBICE_BUILDLINK3_MK

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
