# $NetBSD$

BUILDLINK_TREE+=	mygui-git

.if !defined(MYGUI_GIT_BUILDLINK3_MK)
MYGUI_GIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mygui-git+=	mygui-git>=20170211
BUILDLINK_PKGSRCDIR.mygui-git?=		../../wip/mygui-git

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.endif	# MYGUI_GIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mygui-git
