# $NetBSD$

BUILDLINK_TREE+=	lua51-luv

.if !defined(LUA51_LUV_BUILDLINK3_MK)
LUA51_LUV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua51-luv+=	lua51-luv>=1.41.0
BUILDLINK_PKGSRCDIR.lua51-luv?=	../../wip/lua-luv

.include "../../devel/libuv/buildlink3.mk"

.endif	# LUA51_LUV_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua51-luv
