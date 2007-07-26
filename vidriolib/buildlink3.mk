# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/26 14:04:31 ivaniclixx Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
VIDRIOLIB_BUILDLINK3_MK:=	${VIDRIOLIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	vidriolib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nvidriolib}
BUILDLINK_PACKAGES+=	vidriolib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}vidriolib

.if !empty(VIDRIOLIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.vidriolib+=	vidriolib>=0.1.20070715.0
BUILDLINK_PKGSRCDIR.vidriolib?=	../../wip/vidriolib
.endif	# VIDRIOLIB_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
