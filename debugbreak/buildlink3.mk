# $NetBSD$

BUILDLINK_TREE+=	debugbreak

.if !defined(DEBUGBREAK_BUILDLINK3_MK)
DEBUGBREAK_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.debugbreak?=	build

BUILDLINK_API_DEPENDS.debugbreak+=	debugbreak>=1.0
BUILDLINK_PKGSRCDIR.debugbreak?=	../../wip/debugbreak
.endif	# DEBUGBREAK_BUILDLINK3_MK

BUILDLINK_TREE+=	-debugbreak
