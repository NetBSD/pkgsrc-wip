# $NetBSD: buildlink3.mk,v 1.6 2010/01/18 09:38:26 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_TREE+=	kyra2

.if !defined(KYRA2_BUILDLINK3_MK)
KYRA2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kyra2+=	kyra2>=2.0.7
BUILDLINK_ABI_DEPENDS.kyra2?=	kyra2>=2.0.7nb2
BUILDLINK_PKGSRCDIR.kyra2?=	../../wip/kyra2

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif # KYRA2_BUILDLINK3_MK

BUILDLINK_TREE+=	-kyra2
