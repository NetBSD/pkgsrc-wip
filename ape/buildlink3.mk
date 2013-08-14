# $NetBSD: buildlink3.mk,v 1.1 2013/08/14 01:26:14 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libbacon?=	build

BUILDLINK_TREE+=	libbacon

.if !defined(LIBBACON_BUILDLINK3_MK)
LIBBACON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbacon+=	libbacon>=1.2.1
BUILDLINK_PKGSRCDIR.libbacon?=	../../wip/libbacon
.endif	# LIBBACON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbacon
