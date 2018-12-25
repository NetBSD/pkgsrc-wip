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
# XXX	BUILDLINK_DEPMETHOD.R-progress?=	build

BUILDLINK_TREE+=	R-progress

.if !defined(R_PROGRESS_BUILDLINK3_MK)
R_PROGRESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-progress+=	R-progress>=1.2.0
BUILDLINK_PKGSRCDIR.R-progress?=	../../wip/R-progress
.endif	# R_PROGRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-progress
