# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/27 16:19:22 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.suitesparse?=	build

BUILDLINK_TREE+=	suitesparse

.if !defined(SUITESPARSE_BUILDLINK3_MK)
SUITESPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suitesparse+=	suitesparse>=3.6.1
BUILDLINK_PKGSRCDIR.suitesparse?=	../../jb-wip/suitesparse

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../math/blas/buildlink3.mk"
#.include "../../math/lapack/buildlink3.mk"
#.include "../../jb-wip/metis/buildlink3.mk"
.endif	# SUITESPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-suitesparse
