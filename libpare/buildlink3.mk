# $NetBSD: buildlink3.mk,v 1.2 2013/08/14 01:33:35 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libpare?=	build

BUILDLINK_TREE+=	libpare

.if !defined(LIBPARE_BUILDLINK3_MK)
LIBPARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpare+=	libpare>=1.1.1
BUILDLINK_PKGSRCDIR.libpare?=	../../wip/libpare
.endif	# LIBPARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpare
