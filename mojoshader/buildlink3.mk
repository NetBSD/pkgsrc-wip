# $NetBSD$

BUILDLINK_TREE+=	mojoshader

.if !defined(MOJOSHADER_BUILDLINK3_MK)
MOJOSHADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mojoshader+=	mojoshader>=0.0.20210110
BUILDLINK_PKGSRCDIR.mojoshader?=	../../wip/mojoshader

.endif	# MOJOSHADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mojoshader
