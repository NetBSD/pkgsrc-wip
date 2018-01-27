# $NetBSD: buildlink3.mk,v 1.8 2010/06/13 22:47:07 thomasklausner Exp $

BUILDLINK_TREE+=	gtkglk

.if !defined(GTKGLK_BUILDLINK3_MK)
GTKGLK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkglk+=	gtkglk>=0.2
BUILDLINK_ABI_DEPENDS.gtkglk?=	gtkglk>=0.2nb2
BUILDLINK_PKGSRCDIR.gtkglk?=	../../wip/gtkglk

BUILDLINK_TRANSFORM+=	l:glk:gtkglk
BUILDLINK_TARGETS+=	buildlink-gtkglk-hook

buildlink-gtkglk-hook:
	${LN} -s gtkglk ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.gtkglk ${BUILDLINK_DIR}/include/glk/Make.glk

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKGLK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglk
