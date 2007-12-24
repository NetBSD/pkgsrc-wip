# $NetBSD: buildlink3.mk,v 1.1 2007/12/24 16:33:18 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PDCURSES_BUILDLINK3_MK:=	${PDCURSES_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pdcurses
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npdcurses}
BUILDLINK_PACKAGES+=	pdcurses
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pdcurses

.if ${PDCURSES_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pdcurses+=	pdcurses>=3.1
BUILDLINK_PKGSRCDIR.pdcurses?=	../../wip/pdcurses
BUILDLINK_TRANSFORM+=		l:panel:xpanel
.endif	# PDCURSES_BUILDLINK3_MK

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
