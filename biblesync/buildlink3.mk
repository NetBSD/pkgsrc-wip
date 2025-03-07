# $NetBSD$

BUILDLINK_TREE+=	biblesync

.if !defined(BIBLESYNC_BUILDLINK3_MK)
BIBLESYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biblesync+=	biblesync>=2.1.0
BUILDLINK_PKGSRCDIR.biblesync?=	../../wip/biblesync

.endif	# BIBLESYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biblesync
