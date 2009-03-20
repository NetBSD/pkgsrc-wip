# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	guichan

.if !defined(GUICHAN_BUILDLINK3_MK)
GUICHAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guichan+=	guichan>=0.6.0
BUILDLINK_PKGSRCDIR.guichan?=	../../wip/guichan

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.endif # GUICHAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-guichan
