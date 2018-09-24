# $NetBSD$

BUILDLINK_TREE+=	angelscript

.if !defined(ANGELSCRIPT_BUILDLINK3_MK)
ANGELSCRIPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.angelscript+=	angelscript>=2.32.0
BUILDLINK_ABI_DEPENDS.angelscript+=	angelscript>=2.32.0
BUILDLINK_PKGSRCDIR.angelscript?=	../../wip/angelscript

.endif # ANGELSCRIPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-angelscript
