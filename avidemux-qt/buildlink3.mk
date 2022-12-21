# $NetBSD$

BUILDLINK_TREE+=	avidemux-qt

.if !defined(AVIDEMUX_QT_BUILDLINK3_MK)
AVIDEMUX_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avidemux-qt+=	avidemux-qt>=2.8.1
BUILDLINK_ABI_DEPENDS.avidemux-qt+=	avidemux-qt>=2.8.1
BUILDLINK_PKGSRCDIR.avidemux-qt?=	../../wip/avidemux-qt

.endif # AVIDEMUX_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-avidemux-qt
