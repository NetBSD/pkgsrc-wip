# $NetBSD: buildlink3.mk,v 1.3 2015/09/16 02:36:53 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.blasr_libcpp?=	build

BUILDLINK_TREE+=	blasr_libcpp

.if !defined(BLASR_LIBCPP_BUILDLINK3_MK)
BLASR_LIBCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blasr_libcpp+=	blasr_libcpp>=2015.08.17
BUILDLINK_PKGSRCDIR.blasr_libcpp?=	../../wip/blasr_libcpp
=======
.endif	# BLASR_LIBCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-blasr_libcpp
