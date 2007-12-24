# $NetBSD: buildlink3.mk,v 1.2 2007/12/24 18:52:00 bsadewitz Exp $

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
.endif	# PDCURSES_BUILDLINK3_MK

.include "../../mk/xaw.buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
