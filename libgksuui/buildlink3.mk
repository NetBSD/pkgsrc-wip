# $NetBSD: buildlink3.mk,v 1.5 2010/06/13 22:47:10 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgksuui1.0?=	build

BUILDLINK_TREE+=	libgksuui1.0

.if !defined(LIBGKSUUI1.0_BUILDLINK3_MK)
LIBGKSUUI1.0_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgksuui1.0+=	libgksuui1.0>=1.0.7
BUILDLINK_ABI_DEPENDS.libgksuui1.0?=	libgksuui1.0>=1.0.7nb1
BUILDLINK_PKGSRCDIR.libgksuui1.0?=	../../wip/libgksuui

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGKSUUI1.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgksuui1.0
