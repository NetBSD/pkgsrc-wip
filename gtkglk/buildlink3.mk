# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	gtkglk

BUILDLINK_API_DEPENDS.gtkglk+=	gtkglk>=0.2
BUILDLINK_ABI_DEPENDS.gtkglk?=	gtkglk>=0.2nb1
BUILDLINK_PKGSRCDIR.gtkglk?=	../../wip/gtkglk

BUILDLINK_TRANSFORM+=   l:glk:gtkglk
BUILDLINK_TARGETS+=     buildlink-gtkglk-hook

buildlink-gtkglk-hook:
	${LN} -s gtkglk ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.gtkglk ${BUILDLINK_DIR}/include/glk/Make.glk

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKGLK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglk
