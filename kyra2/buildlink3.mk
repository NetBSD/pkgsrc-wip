# $NetBSD: buildlink3.mk,v 1.8 2013/01/01 01:15:36 othyro Exp $

BUILDLINK_TREE+=	kyra2

.if !defined(KYRA2_BUILDLINK3_MK)
KYRA2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyra2+=	kyra2>=2.1.3
BUILDLINK_ABI_DEPENDS.kyra2?=	kyra2>=2.1.3
BUILDLINK_PKGSRCDIR.kyra2?=	../../wip/kyra2

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif # KYRA2_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyra2
