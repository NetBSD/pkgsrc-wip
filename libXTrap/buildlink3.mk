# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/02 11:16:13 jsonn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXTRAP_BUILDLINK3_MK:=	${LIBXTRAP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXTrap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXTrap}
BUILDLINK_PACKAGES+=	libXTrap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXTrap

.if ${LIBXTRAP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXTrap+=	libXTrap>=1.0.0
BUILDLINK_PKGSRCDIR.libXTrap?=	../../wip/libXTrap
.endif	# LIBXTRAP_BUILDLINK3_MK

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
