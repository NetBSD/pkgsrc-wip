# $NetBSD: buildlink3.mk,v 1.7 2010/06/13 22:47:09 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_TREE+=	kyra

.if !defined(KYRA_BUILDLINK3_MK)
KYRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyra+=	kyra>=1.6.5
BUILDLINK_ABI_DEPENDS.kyra?=	kyra>=1.6.5nb3
BUILDLINK_PKGSRCDIR.kyra?=	../../wip/kyra

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif # KYRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyra
