# $NetBSD: buildlink3.mk,v 1.1 2015/01/28 16:40:51 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.parafly?=	build

BUILDLINK_TREE+=	parafly

.if !defined(PARAFLY_BUILDLINK3_MK)
PARAFLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.parafly+=	parafly>=2013.01.21
BUILDLINK_PKGSRCDIR.parafly?=	../../wip/parafly
.endif	# PARAFLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-parafly
