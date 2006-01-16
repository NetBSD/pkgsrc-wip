# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/01/16 23:12:19 poppnk Exp $
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

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGKSUUI1.0_BUILDLINK3_MK:=	${LIBGKSUUI1.0_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgksuui1.0
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgksuui1.0}
BUILDLINK_PACKAGES+=	libgksuui1.0

.if !empty(LIBGKSUUI1.0_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgksuui1.0+=	libgksuui1.0>=1.0.7
BUILDLINK_PKGSRCDIR.libgksuui1.0?=	../../wip/libgksuui
.endif	# LIBGKSUUI1.0_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
