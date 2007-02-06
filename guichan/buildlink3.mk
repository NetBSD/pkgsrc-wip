# $NetBSD: buildlink3.mk,v 1.2 2007/02/06 21:18:28 netcap Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUICHAN_BUILDLINK3_MK:=	${GUICHAN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	guichan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguichan}
BUILDLINK_PACKAGES+=	guichan
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}guichan

.if ${GUICHAN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.guichan+=	guichan>=0.6.0
BUILDLINK_PKGSRCDIR.guichan?=	../../wip/guichan
BUILDLINK_DEPMETHOD.guichan?=	build
.endif	# GUICHAN_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
