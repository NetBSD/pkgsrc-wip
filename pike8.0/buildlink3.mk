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
# XXX	BUILDLINK_DEPMETHOD.pike8.0?=	build

BUILDLINK_TREE+=	pike8.0

.if !defined(PIKE8.0_BUILDLINK3_MK)
PIKE8.0_BUILDLINK3_MK:=

BUILDLINK_INCDIRS.pike8.0+=	include/pike8.0

BUILDLINK_API_DEPENDS.pike8.0+=	pike8.0>=8.0.498
BUILDLINK_PKGSRCDIR.pike8.0?=	../../lang/pike8.0

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.endif	# PIKE8.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-pike8.0
