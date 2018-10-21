# $NetBSD$

BUILDLINK_TREE+=	luabind

.if !defined(LUABIND_BUILDLINK3_MK)
LUABIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.luabind+=	luabind>=0.9.2
BUILDLINK_ABI_DEPENDS.luabind+=	luabind>=0.9.2
BUILDLINK_PKGSRCDIR.luabind?=	../../wip/luabind

.endif # LUABIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-luabind
