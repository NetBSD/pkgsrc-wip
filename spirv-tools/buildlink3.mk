# $NetBSD$

BUILDLINK_TREE+=	spirv-tools

.if !defined(SPIRV_TOOLS_BUILDLINK3_MK)
SPIRV_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spirv-tools+=	spirv-tools>=2024.2
BUILDLINK_PKGSRCDIR.spirv-tools?=	../../wip/spirv-tools

.endif	# SPIRV_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-spirv-tools
