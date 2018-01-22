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
# XXX	BUILDLINK_DEPMETHOD.libepoll-shim?=	build

BUILDLINK_TREE+=	libepoll-shim

.if !defined(LIBEPOLL_SHIM_BUILDLINK3_MK)
LIBEPOLL_SHIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoll-shim+=	libepoll-shim>=0.0.20161220
BUILDLINK_PKGSRCDIR.libepoll-shim?=	../../wip/libepoll-shim
.endif	# LIBEPOLL_SHIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoll-shim
