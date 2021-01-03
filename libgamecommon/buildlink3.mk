# $NetBSD$

BUILDLINK_TREE+=	libgamecommon

.if !defined(LIBGAMECOMMON_BUILDLINK3_MK)
LIBGAMECOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgamecommon+=	libgamecommon>=1.2
BUILDLINK_PKGSRCDIR.libgamecommon?=	../../wip/libgamecommon

.endif	# LIBGAMECOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgamecommon
