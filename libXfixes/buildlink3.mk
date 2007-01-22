# $NetBSD: buildlink3.mk,v 1.10 2007/01/22 10:02:19 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFIXES_BUILDLINK3_MK:=	${LIBXFIXES_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXfixes
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXfixes}
BUILDLINK_PACKAGES+=	libXfixes
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXfixes

.if ${LIBXFIXES_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXfixes+=	libXfixes>=4.0.3
BUILDLINK_PKGSRCDIR.libXfixes?=	../../wip/libXfixes
.endif	# LIBXFIXES_BUILDLINK3_MK

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
