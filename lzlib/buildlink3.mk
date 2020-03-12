# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.lzlib?=	build

BUILDLINK_TREE+=	lzlib

.if !defined(LZLIB_BUILDLINK3_MK)
LZLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzlib+=	lzlib>=1.11
BUILDLINK_PKGSRCDIR.lzlib?=	../../wip/lzlib
.endif	# LZLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzlib
