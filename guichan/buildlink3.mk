# $NetBSD: buildlink3.mk,v 1.6 2010/06/13 22:47:07 thomasklausner Exp $

BUILDLINK_TREE+=	guichan

.if !defined(GUICHAN_BUILDLINK3_MK)
GUICHAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guichan+=	guichan>=0.6.0
BUILDLINK_ABI_DEPENDS.guichan?=	guichan>=0.6.0nb2
BUILDLINK_PKGSRCDIR.guichan?=	../../wip/guichan

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.endif # GUICHAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-guichan
