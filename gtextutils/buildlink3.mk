# $NetBSD$

BUILDLINK_TREE+=	libgtextutils

.if !defined(LIBGTEXTUTILS_BUILDLINK3_MK)
LIBGTEXTUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtextutils+=	libgtextutils>=0.7
BUILDLINK_PKGSRCDIR.libgtextutils?=	../../wip/gtextutils
.endif	# LIBGTEXTUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtextutils
