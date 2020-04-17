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
# XXX	BUILDLINK_DEPMETHOD.cppzmq?=	build

BUILDLINK_TREE+=	cppzmq

.if !defined(CPPZMQ_BUILDLINK3_MK)
CPPZMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppzmq+=	cppzmq>=4.6.0
BUILDLINK_PKGSRCDIR.cppzmq?=	../../wip/cppzmq

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../net/zeromq/buildlink3.mk"
.endif	# CPPZMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppzmq
