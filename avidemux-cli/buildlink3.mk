# $NetBSD$

BUILDLINK_TREE+=	avidemux-cli

.if !defined(AVIDEMUX_CLI_BUILDLINK3_MK)
AVIDEMUX_CLI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avidemux-cli+=	avidemux-cli>=2.8.1
BUILDLINK_ABI_DEPENDS.avidemux-cli+=	avidemux-cli>=2.8.1
BUILDLINK_PKGSRCDIR.avidemux-cli?=	../../wip/avidemux-cli

.endif # AVIDEMUX_CLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-avidemux-cli
