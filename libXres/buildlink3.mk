# $NetBSD: buildlink3.mk,v 1.8 2007/01/23 13:39:05 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRES_BUILDLINK3_MK:=	${LIBXRES_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXres
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXres}
BUILDLINK_PACKAGES+=	libXres
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXres

.if ${LIBXRES_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXres+=	libXres>=1.0.3
BUILDLINK_PKGSRCDIR.libXres?=	../../wip/libXres
.endif	# LIBXRES_BUILDLINK3_MK

.include "../../wip/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
