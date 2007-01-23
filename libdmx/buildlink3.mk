# $NetBSD: buildlink3.mk,v 1.1 2007/01/23 08:44:10 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDMX_BUILDLINK3_MK:=	${LIBDMX_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libdmx
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdmx}
BUILDLINK_PACKAGES+=	libdmx
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libdmx

.if ${LIBDMX_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libdmx+=	libdmx>=1.0.2
BUILDLINK_PKGSRCDIR.libdmx?=	../../wip/libdmx
.endif	# LIBDMX_BUILDLINK3_MK

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/dmxproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
