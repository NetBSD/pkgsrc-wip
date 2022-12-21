# $NetBSD$

BUILDLINK_TREE+=	avidemux

.if !defined(AVIDEMUX_BUILDLINK3_MK)
AVIDEMUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avidemux+=	avidemux>=2.8.1
BUILDLINK_ABI_DEPENDS.avidemux+=	avidemux>=2.8.1
BUILDLINK_PKGSRCDIR.avidemux?=		../../wip/avidemux

.endif # AVIDEMUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-avidemux
