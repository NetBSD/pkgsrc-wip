# $NetBSD: buildlink3.mk,v 1.6 2007/01/23 06:24:59 bsadewitz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXDMCP_BUILDLINK3_MK:=	${LIBXDMCP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXdmcp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXdmcp}
BUILDLINK_PACKAGES+=	libXdmcp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXdmcp

.if ${LIBXDMCP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXdmcp+=	libXdmcp>=1.0.2
BUILDLINK_PKGSRCDIR.libXdmcp?=	../../wip/libXdmcp
.endif	# LIBXDMCP_BUILDLINK3_MK

.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
