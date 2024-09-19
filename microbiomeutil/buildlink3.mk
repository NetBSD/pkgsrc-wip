# $NetBSD$

BUILDLINK_TREE+=	microbiomeutil

.if !defined(MICROBIOMEUTIL_BUILDLINK3_MK)
MICROBIOMEUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.microbiomeutil+=	microbiomeutil>=r20110519
BUILDLINK_PKGSRCDIR.microbiomeutil?=	../../wip/microbiomeutil
.endif	# MICROBIOMEUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-microbiomeutil
