# $NetBSD$

BUILDLINK_TREE+=	LuaJIT2

.if !defined(LUAJIT2_BUILDLINK3_MK)
LUAJIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.0.3
BUILDLINK_PKGSRCDIR.LuaJIT2?=	../../wip/LuaJIT2
BUILDLINK_INCDIRS.LuaJIT2+=	include/luajit-2.0
.endif	# LUAJIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-LuaJIT2
