# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgtextutils?=	build

BUILDLINK_TREE+=	libgtextutils

.if !defined(LIBGTEXTUTILS_BUILDLINK3_MK)
LIBGTEXTUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtextutils+=	libgtextutils>=0.7
BUILDLINK_PKGSRCDIR.libgtextutils?=	../../wip/gtextutils
.endif	# LIBGTEXTUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtextutils
