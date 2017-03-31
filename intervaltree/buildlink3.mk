# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX

BUILDLINK_TREE+=	intervaltree

.if !defined(INTERVALTREE_BUILDLINK3_MK)
INTERVALTREE_BUILDLINK3_MK:=
BUILDLINK_DEPMETHOD.intervaltree?=	build

BUILDLINK_API_DEPENDS.intervaltree+=	intervaltree>=49a0e290efaaa760e0b03e52ca18ac03e7582f23
BUILDLINK_PKGSRCDIR.intervaltree?=	../../wip/intervaltree
.endif	# INTERVALTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-intervaltree
