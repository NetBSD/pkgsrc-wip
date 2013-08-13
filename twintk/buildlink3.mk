# $NetBSD: buildlink3.mk,v 1.1 2013/08/13 23:07:15 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.twintk?=	build

BUILDLINK_TREE+=	twintk

.if !defined(TWINTK_BUILDLINK3_MK)
TWINTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twintk+=	twintk>=0.9.3
BUILDLINK_PKGSRCDIR.twintk?=	../../jb-wip/twintk

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../jb-wip/libbacon/buildlink3.mk"
.endif	# TWINTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-twintk
