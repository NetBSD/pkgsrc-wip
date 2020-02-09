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
# XXX	BUILDLINK_DEPMETHOD.minizip?=	build

BUILDLINK_TREE+=	minizip

.if !defined(MINIZIP_BUILDLINK3_MK)
MINIZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minizip+=	minizip>=1.2.11
BUILDLINK_PKGSRCDIR.minizip?=	../../wip/minizip

.include "../../devel/zlib/buildlink3.mk"
.endif	# MINIZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-minizip
