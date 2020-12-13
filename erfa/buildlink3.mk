# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.18.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.erfa?=	build

BUILDLINK_TREE+=	erfa

.if !defined(ERFA_BUILDLINK3_MK)
ERFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erfa+=	erfa>=1.7.1
BUILDLINK_PKGSRCDIR.erfa?=	../../math/erfa
.endif	# ERFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-erfa
