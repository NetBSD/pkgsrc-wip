# $NetBSD: buildlink3.mk,v 1.3 2004/05/23 23:20:55 dillo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKGLK_BUILDLINK3_MK:=	${GTKGLK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkglk}
BUILDLINK_PACKAGES+=	gtkglk

.if !empty(GTKGLK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkglk+=	gtkglk>=0.2
BUILDLINK_PKGSRCDIR.gtkglk?=	../../wip/gtkglk

BUILDLINK_TRANSFORM+=   l:glk:gtkglk
BUILDLINK_TARGETS+=     buildlink-gtkglk-hook

buildlink-gtkglk-hook:
	${LN} -s gtkglk ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.gtkglk ${BUILDLINK_DIR}/include/glk/Make.glk

.endif	# GTKGLK_BUILDLINK3_MK

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
